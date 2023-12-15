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
    bool start = false, neg = false;
    int ans = 0;
	while(true) {
		c = getchar();
        if((c < '0' || c > '9') && c != '-') {
            if(start) break;
            else continue;
        }
        ans *= 10;
		start = true;
		if(c == '-') neg = true;
		else ans += c - '0';
	}
    return neg ? -ans : ans;
}

struct Item {
    int cost = 0;
    int damage = 0;
    int armor = 0;

    Item& operator += (const Item& other) {
        cost += other.cost;
        damage += other.damage;
        armor += other.armor;
        return *this;
    }
};

vector<Item> weapons = {
    {8, 4, 0},
    {10, 5, 0},
    {25, 6, 0},
    {40, 7, 0},
    {74, 8, 0},
};
vector<Item> armor = {
    {13, 0, 1},
    {31, 0, 2},
    {53, 0, 3},
    {75, 0, 4},
    {102, 0, 5},
};
vector<Item> rings = {
    {25, 1, 0},
    {50, 2, 0},
    {100, 3, 0},
    {20, 0, 1},
    {40, 0, 2},
    {80, 0, 3},
};

vector<int> getMasks(int n, int l, int r) {
    vector<int> v;
    rep(mask, 0, (1 << n) - 1) {
        int cnt = pcnt(mask);
        if(cnt < l || cnt > r) continue;
        v.pb(mask);
    }
    return v;
}

bool wins(int bossHP, int bossDamage, int bossArmor, int heroHP, int heroDamage, int heroArmor) {
    int turn = 0;
    while(bossHP > 0 && heroHP > 0) {
        if(turn % 2 == 0) {
            bossHP -= max(1, heroDamage - bossArmor);
        } else {
            heroHP -= max(1, bossDamage - heroArmor);
        }
        turn++;
    }
    return heroHP > 0;
}

signed main() {
    freopen("input.txt", "r", stdin);
    int heroHP = 100;
    int bossHP = readInt();
    int bossDamage = readInt();
    int bossArmor = readInt();
    int ans = 0;
    vector<int> maskWeapon = getMasks(sz(weapons), 1, 1);
    vector<int> maskArmor = getMasks(sz(armor), 0, 1);
    vector<int> maskRing = getMasks(sz(rings), 0, 2);
    rall(m1, maskWeapon) {
        rall(m2, maskArmor) {
            rall(m3, maskRing) {
                Item total;
                rep(i, 0, sz(weapons) - 1) {
                    if(m1 & (1 << i)) {
                        total += weapons[i];
                    }
                }
                rep(i, 0, sz(armor) - 1) {
                    if(m2 & (1 << i)) {
                        total += armor[i];
                    }
                }
                rep(i, 0, sz(rings) - 1) {
                    if(m3 & (1 << i)) {
                        total += rings[i];
                    }
                }
                if(!wins(bossHP, bossDamage, bossArmor, heroHP, total.damage, total.armor)) {
                    ans = max(ans, total.cost);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
