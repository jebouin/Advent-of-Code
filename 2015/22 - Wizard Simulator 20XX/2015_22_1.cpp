#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define ina(n,a) cin >> n; for(int i = 1; i <= n; i++) cin >> a[i]
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            coyhhhhhhyoc    
#define next          sdNNNmNNNNNNNmds  
#define y0           hNNNNy_yNNNNNN_sNh
#define y1          mNNNNNdtdNNNNNNtsNNm
#define yn          mNNNNNNNNy___smNNNms
#define tm            oooooosyysooooot 
#define read               tyhyt        
#define rank              ytmNmo         
#define index              yyy
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 1000000007
#ifndef LOCAL
#define endl "\n"
#define cerr if(0) cerr
#endif

typedef long long ll;
using namespace std;

int readInt() {
    char c;
    bool start = false;
    int ans = 0;
	while(true) {
		c = getchar();
        if(isdigit(c)) {
            ans = 10 * ans + c - '0';
            start = true;
        } else if(start) {
            break;
        }
	}
    return ans;
}

const int INF = 1'000'000'000;
int bossDamage;

struct State {
    int bossHP;
    int hp = 50, mana = 500, spent = 0;
    bool heroTurn = true;
    int effectShield = 0, effectPoison = 0, effectRecharge = 0;

    State(int bossHP) : bossHP(bossHP) {}
    bool operator<(const State &o) const {
        return tie(bossHP, hp, mana, spent, heroTurn, effectShield, effectPoison, effectRecharge) < tie(o.bossHP, o.hp, o.mana, o.spent, o.heroTurn, o.effectShield, o.effectPoison, o.effectRecharge);
    }
    int getArmor() {
        return effectShield ? 7 : 0;
    }
    void spendMana(int amount) {
        mana -= amount;
        spent += amount;
    }
    bool beforeTurn() {
        if(effectShield) {
            effectShield--;
        }
        if(effectPoison) {
            bossHP -= 3;
            effectPoison--;
            if(bossHP <= 0) {
                return false;
            }
        }
        if(effectRecharge) {
            mana += 101;
            effectRecharge--;
        }
        return true;
    }
    void afterTurn() {
        heroTurn = !heroTurn;
    }
    void playBoss() {
        if(!beforeTurn()) return;
        int damage = max(1, bossDamage - getArmor());
        hp -= damage;
        afterTurn();
    }
    void playMissile() {
        if(!beforeTurn()) return;
        spendMana(53);
        bossHP -= 4;
        afterTurn();
    }
    void playDrain() {
        if(!beforeTurn()) return;
        spendMana(73);
        bossHP -= 2;
        hp += 2;
        afterTurn();
    }
    void playShield() {
        if(!beforeTurn()) return;
        if(effectShield) {
            hp = 0;
        } else {
            spendMana(113);
            effectShield = 6;
        }
        afterTurn();
    }
    void playPoison() {
        if(!beforeTurn()) return;
        if(effectPoison) {
            hp = 0;
        } else {
            spendMana(173);
            effectPoison = 6;
        }
        afterTurn();
    }
    void playRecharge() {
        if(!beforeTurn()) return;
        if(effectRecharge) {
            hp = 0;
        } else {
            spendMana(229);
            effectRecharge = 5;
        }
        afterTurn();
    }
};

int ans = INF;
set<State> st;

void solve(State s) {
    if(s.hp <= 0 || s.mana < 0) return;
    if(s.bossHP <= 0) {
        ans = min(ans, s.spent);
        st.insert(s);
        return;
    }
    if(s.spent > ans) return;
    if(st.find(s) != st.end()) return;
    st.insert(s);
    if(s.heroTurn) {
        State t = s;
        t.playMissile();
        solve(t);
        t = s;
        t.playDrain();
        solve(t);
        t = s;
        t.playShield();
        solve(t);
        t = s;
        t.playPoison();
        solve(t);
        t = s;
        t.playRecharge();
        solve(t);
    } else {
        s.playBoss();
        solve(s);
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    int bossHP = readInt();
    bossDamage = readInt();
    State s(bossHP);
    solve(s);
    cout << ans << endl;
    return 0;
}
