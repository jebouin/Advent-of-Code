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

const int INF = 1'000'000'000;
const int N = 1111;
string grid[N];
int n, m, si, sj;

int dist(int x, int y) {
    int dx = x - si, dy = y - sj;
    return dx * dx + dy * dy;
}

bool comp(const pair<int, int>& a1, const pair<int, int>& a2) {
    double an1 = atan2(a1.se, a1.fi);
    double an2 = atan2(a2.se, a2.fi);
    return an1 > an2;
}

pair<int, int> normalize(int fi, int fj, int ti, int tj) {
    int di = ti - fi, dj = tj - fj;
    int g = __gcd(abs(di), abs(dj));
    return make_pair(di / g, dj / g);
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    set<pair<int, int> > all;
    while(cin >> s) {
        grid[++n] = " " + s;
        m = sz(s);
        rep(j, 1, m) {
            if(grid[n][j] == '#') {
                all.insert(make_pair(n, j));
            }
        }
    }
    int ans = 0;
    set<pair<int, int> > bst;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(grid[i][j] == '.') continue;
            set<pair<int, int> > st;
            rall(p, all) {
                if(p.fi == i && p.se == j) continue;
                st.insert(normalize(i, j, p.fi, p.se));
            }
            int cur = sz(st);
            if(cur > ans) {
                ans = cur, si = i, sj = j, bst = st;
            }
        }
    }
    all.erase({si, sj});
    vector<pair<int, int> > dirs(rng(bst)), shot;
    sort(rng(dirs), comp);
    while(sz(all)) {
        rall(dir, dirs) {
            pair<int, int> p;
            int bd = INF;
            rall(pos, all) {
                pair<int, int> dp = normalize(si, sj, pos.fi, pos.se);
                if(dp == dir) {
                    int curd = dp.fi * dp.fi + dp.se * dp.se;
                    if(curd < bd) {
                        p = pos;
                        bd = curd;
                    }
                }
            }
            if(bd < INF) {
                all.erase(p);
                shot.pb(p);
            }
        }
    }
    int x = shot[199].se - 1, y = shot[199].fi - 1;
    cout << x * 100 + y << endl;
    return 0;
}
