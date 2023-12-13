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
#define rall(x,a) for(auto& x : a)
#define MOD 1000000007
#ifndef LOCAL
#define endl "\n"
#define cerr if(0) cerr
#endif
#define int long long

typedef long long ll;
using namespace std;

int readInt(stringstream& ss) {
    int ans = 0;
    bool start = false;
    char c;
    while(ss >> c) {
        if(!isdigit(c)) {
            if(start) break;
            else continue;
        }
        start = true;
        ans = 10 * ans + c - '0';
    }
    return ans;
}

class Group {
    private:
        int units, hp, att, init, chosen;
        bool dead, infection, isTarget;
        string type;
        set<string> weak, immune;

    public:
        Group(string line, bool infection) : dead(false), infection(infection) {
            stringstream ss(line);
            units = readInt(ss);
            hp = readInt(ss);
            att = readInt(ss);
            init = readInt(ss);
            int pos = line.find("weak");
            if(pos != (int)string::npos) {
                pos += 6;
                do {
                    pos += 2;
                    string type;
                    while(isalpha(line[pos])) {
                        type += line[pos];
                        pos++;
                    }
                    weak.insert(type);
                } while(line[pos] == ',');
            }
            pos = line.find("immune");
            if(pos != (int)string::npos) {
                pos += 8;
                do {
                    pos += 2;
                    string type;
                    while(isalpha(line[pos])) {
                        type += line[pos];
                        pos++;
                    }
                    immune.insert(type);
                } while(line[pos] == ',');
            }
            pos = line.find("damage");
            pos -= 2;
            while(isalpha(line[pos])) {
                type += line[pos];
                pos--;
            }
            reverse(rng(type));
        }

        void boost(int boost) {
            att += boost;
        }

        int getEffectivePower() const {
            return units * att;
        }

        int getDamage(Group& target) {
            if(target.immune.find(type) != target.immune.end()) {
                return 0;
            }
            int damage = getEffectivePower();
            if(target.weak.find(type) != target.weak.end()) {
                damage <<= 1;
            }
            return damage;
        }

        void hit(Group& other) {
            if(dead || other.dead) return;
            int damage = getDamage(other);
            int killed = damage / other.hp;
            other.units -= killed;
            if(other.units <= 0) {
                other.units = 0;
                other.dead = true;
            }
        }

        int getUnits() const { return units; }
        int getInit() const { return init; }
        int getChosen() const { return chosen; }
        bool getInfection() const { return infection; }
        bool getDead() const { return dead; }
        void resetTarget() { isTarget = false, chosen = 0; }

        void choseTarget(vector<Group>& groups) {
            Group *bg = NULL;
            int bd = -1, bp = -1, bin = -1;
            rall(tg, groups) {
                if(tg.isTarget || infection == tg.infection) continue;
                int damage = getDamage(tg);
                if(damage == 0) continue;
                int ep = tg.getEffectivePower(), in = tg.getInit();
                if(damage > bd) {
                    bd = damage;
                    chosen = tg.init;
                    bg = &tg;
                    bp = ep;
                    bin = in;
                } else if(damage == bd && ep > bp) {
                    chosen = tg.init;
                    bg = &tg;
                    bp = ep;
                    bin = in;
                } else if(damage == bd && ep == bp && in > bin) {
                    chosen = tg.init;
                    bg = &tg;
                    bin = in;
                }
            }
            if(bg != NULL) {
                bg->isTarget = true;
            }
        }
};

bool compareSelection(const Group& g1, const Group& g2) {
    int p1 = g1.getEffectivePower(), p2 = g2.getEffectivePower();
    int i1 = g1.getInit(), i2 = g2.getInit();
    return make_pair(p1, i1) > make_pair(p2, i2);
}

bool compareAttack(const Group& g1, const Group& g2) {
    return g1.getInit() > g2.getInit();
}

vector<Group> groups, initGroups;

int solve(int b) {
    groups = initGroups;
    rall(group, groups) {
        if(!group.getInfection()) {
            group.boost(b);
        }
    }
    rep(o, 1, 100000) {
        sort(rng(groups), compareSelection);
        rall(group, groups) {
            group.resetTarget();
        }
        rall(group, groups) {
            group.choseTarget(groups);
        }
        sort(rng(groups), compareAttack);
        rall(group, groups) {
            rall(other, groups) {
                if(group.getChosen() == other.getInit()) {
                    group.hit(other);
                    break;
                }
            }
        }
        vector<Group> newGroups;
        int ua = 0, ub = 0;
        rall(group, groups) {
            if(!group.getDead()) {
                if(group.getInfection()) {
                    ub += group.getUnits();
                } else {
                    ua += group.getUnits();
                }
                newGroups.pb(group);
            }
        }
        groups = newGroups;
        if(ua == 0 || ub == 0) {
            return ua;
        }
    }
    return 0;
}

signed main() {
    freopen("input.txt", "r", stdin);
    bool infection = false;
    string line;
    while(getline(cin, line)) {
        if(line[1] == 'n') {
            infection = true;
        }
        if(line.empty() || !isdigit(line[0])) continue;
        initGroups.pb(Group(line, infection));
    }
    int b = 0, ans = 0;
    while(!ans) {
        ans = solve(b++);
    }
    cout << ans << endl;    
    return 0;
}
