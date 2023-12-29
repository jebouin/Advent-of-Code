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
#define int long long

typedef long long ll;
using namespace std;

const int DI[] = {0, 1, 0, -1};
const int DJ[] = {1, 0, -1, 0};
const int N = 222;
string grid[N];
set<pair<int, int> > st[33333333];
int n, m, si, sj;

int solve(int cnt) {
    queue<pair<pair<int, int>, int> > q;
    q.push({{si, sj}, 0});
    st[0].insert({si, sj});
    rep(i, 0, cnt) {
        st[i].clear();
    }
    while(sz(q)) {
        auto p = q.front();
        q.pop();
        st[p.se].insert(p.fi);
        if(p.se > cnt) continue;
        int nd = p.se + 1;
        rep(d, 0, 3) {
            int ii = ((p.fi.fi + DI[d] - 1) % n + n) % n + 1;
            int jj = ((p.fi.se + DJ[d] - 1) % m + m) % m + 1;
            if(grid[ii][jj] == '#') continue;
            pair<int, int> pp = {p.fi.fi + DI[d], p.fi.se + DJ[d]};
            if(st[nd].find(pp) == st[nd].end()) {
                q.push({pp, nd});
                st[nd].insert(pp);
            }
        }
    }
    return sz(st[cnt]);
}

int f(int k) {
    return solve(k * n + n / 2);
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        n++;
        grid[n] = "#" + s + "#";
        m = sz(s);
        rep(j, 1, m) {
            if(s[j - 1] == 'S') {
                si = n;
                sj = j;
                grid[n][j] = '.';
            }
        }
    }
    grid[0] = string(m + 2, '#');
    grid[n + 1] = string(m + 2, '#');
    int d1 = f(1) - f(0), d2 = f(2) - f(1);
    int dd = d2 - d1;
    int need = 26501365;
    int x = (need - n / 2) / n + 1;
    vector<int> v = {f(0), f(1)};
    while(sz(v) < x) {
        int y1 = v.back(), y2 = v[sz(v) - 2];
        v.pb({dd + 2 * y1 - y2});
    }
    cout << v.back();
    return 0;
}
