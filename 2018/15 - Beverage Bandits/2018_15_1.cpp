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

typedef long long ll;
using namespace std;

class Unit;

const int DX[] = {-1, 0, 0, 1};
const int DY[] = {0, -1, 1, 0};
vector<string> input, grid;
vector<Unit> units;

class Unit {
    private:
        int x, y, att, hp;
        bool g, dead;

    public:
        Unit(int x, int y, bool g, int hp = 200, int att = 3) : x(x), y(y), att(att), hp(hp), g(g), dead(false) {

        }

        bool operator == (const Unit& other) {
            return getPos() == other.getPos();
        }

        bool operator < (const Unit& other) {
            return make_pair(x, y) < make_pair(other.x, other.y);
        }

        void printHP(ostream& stream) const {
            stream << getTypeChar() << "(" << hp << ")";
        }

        pair<int, int> getPos() const {
            return make_pair(x, y);
        }

        int getHP() const {
            return hp;
        }

        char getTypeChar() const {
            return g ? 'G' : 'E';
        }

        void move(pair<int, int> pos) {
            x = pos.fi;
            y = pos.se;
        }

        void hit(Unit& other) {
            other.hp -= att;
            if(other.hp <= 0) {
                other.dead = true;
            }
        }

        bool isDead() {
            return dead;
        }
};

ostream& operator << (ostream& stream, const Unit& u) {
    u.printHP(stream);
    return stream;
}

int n, m;

void readGrid() {
    input.clear();
    string line;
    while(cin >> line) {
        input.pb(line);
        m = sz(line);
    }
    n = sz(input);
}

void parseGrid() {
    grid.clear();
    units.clear();
    rep(i, 0, n - 1) {
        string line = input[i];
        rep(j, 0, m - 1) {
            if(line[j] == '.') {
                line[j] = ' ';
            } else if(line[j] != '#') {
                units.pb(Unit(i, j, line[j] == 'G'));
                line[j] = ' ';
            }
        }
        grid.pb(line);
    }
}

bool isFree(pair<int, int> pos) {
    if(grid[pos.fi][pos.se] != ' ') {
        return false;
    }
    rall(u, units) {
        if(!u.isDead() && u.getPos() == pos) {
            return false;
        }
    }
    return true;
}

vector<vector<int> > bfs(pair<int, int> from, pair<int, int> to) {
    vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
    dist[from.fi][from.se] = 0;
    queue<pair<int, int> > q;
    q.push(from);
    while(sz(q)) {
        pair<int, int> pos = q.front();
        int cd = dist[pos.fi][pos.se];
        q.pop();
        rep(d, 0, 3) {
            pair<int, int> poss(pos.fi + DX[d], pos.se + DY[d]);
            int& nd = dist[poss.fi][poss.se];
            if((poss == to || isFree(poss)) && cd + 1 < nd) {
                nd = cd + 1;
                q.push(poss);
            }
        }
    }
    return dist;
}

set<pair<int, int> > getRanges(Unit& from) {
    set<pair<int, int> > ans;
    rall(other, units) {
        if(from.getTypeChar() == other.getTypeChar() || other.isDead()) continue;
        rep(d, 0, 3) {
            pair<int, int> pos(other.getPos().fi + DX[d], other.getPos().se + DY[d]);
            if(isFree(pos) || pos == from.getPos()) {
                ans.insert(pos);
            }
        }
    }
    return ans;
}

int getElfCount() {
    int ans = 0;
    rall(unit, units) {
        if(unit.getTypeChar() == 'E' && !unit.isDead()) ans++;
    }
    return ans;
}

bool gameEnded() {
    set<char> sc;
    rall(unit, units) {
        if(unit.isDead()) continue;
        sc.insert(unit.getTypeChar());
    }
    return sz(sc) == 1;
}

pair<bool, int> getOutcome() {
    parseGrid();
    sort(rng(units));
    int elves = getElfCount();
    rep(o, 1, 500) {
        rall(unit, units) {
            if(gameEnded()) {
                int code = 0;
                rall(unit, units) {
                    if(unit.isDead()) continue;
                    code += unit.getHP();
                }
                code *= o - 1;
                return make_pair(getElfCount() == elves, code);
            }
            if(unit.isDead()) continue;
            set<pair<int, int> > ranges = getRanges(unit);
            bool inRange = false;
            rall(p, ranges) {
                if(p == unit.getPos()) {
                    inRange = true;
                    break;
                }
            }
            if(!inRange) {
                set<pair<int, pair<int, int> > > reachable;
                rall(p, ranges) {
                    vector<vector<int> > dist = bfs(p, unit.getPos());
                    int d = dist[unit.getPos().fi][unit.getPos().se];
                    if(d < INT_MAX) {
                        reachable.insert(make_pair(d, p));
                    }
                }
                if(sz(reachable)) {
                    pair<int, int> target = reachable.begin()->se;
                    vector<vector<int> > dist = bfs(target, unit.getPos());
                    set<pair<int, pair<int, int> > > movePoss;
                    rep(d, 0, 3) {
                        pair<int, int> poss(unit.getPos().fi + DX[d], unit.getPos().se + DY[d]);
                        int di = dist[poss.fi][poss.se];
                        if(di < INT_MAX) {
                            movePoss.insert(make_pair(di, poss));
                        }
                    }
                    pair<int, int> movePos = movePoss.begin()->se;
                    unit.move(movePos);
                }
            }
            set<pair<int, pair<int, int> > > targets;
            rall(other, units) {
                if(other.isDead()) continue;
                if(other.getTypeChar() != unit.getTypeChar() && abs(unit.getPos().fi - other.getPos().fi) + abs(unit.getPos().se - other.getPos().se) == 1) {
                    targets.insert(make_pair(other.getHP(), other.getPos()));
                }
            }
            if(sz(targets)) {
                pair<int, int> target = targets.begin()->se;
                rall(other, units) {
                    if(other.getPos() == target) {
                        unit.hit(other);
                    }
                }
            }
        }
        vector<Unit> sunits(units);
        units.clear();
        rall(unit, sunits) {
            if(!unit.isDead()) {
                units.pb(unit);
            }
        }
        sort(rng(units));
    }
    return {-1, -1};
}

signed main() {
    freopen("input.txt", "r", stdin);
    readGrid();
    pair<bool, int> outcome = getOutcome();
    cout << outcome.se << endl;
    return 0;
}
