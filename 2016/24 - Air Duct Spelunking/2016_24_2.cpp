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

const int INF = 1'000'000'000;
const int DI[] = {0, 1, 0, -1};
const int DJ[] = {1, 0, -1, 0};
const int N = 222, K = 11;
string grid[N];
int pi[K], pj[K], dist[K][K];
int di[N][N];
int n, m, k;

int bfs(int fi, int fj, int ti, int tj) {
    rep(i, 1, n) {
        fill(di[i] + 1, di[i] + m + 1, INF);
    }
    di[fi][fj] = 0;
    queue<pair<int, int> > q;
    q.push({fi, fj});
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        rep(d, 0, 3) {
            int ii = p.fi + DI[d];
            int jj = p.se + DJ[d];
            if(ii < 1 || jj < 1 || ii > n || jj > m || grid[ii][jj] == '#') continue;
            if(di[ii][jj] > di[p.fi][p.se] + 1) {
                di[ii][jj] = di[p.fi][p.se] + 1;
                q.push({ii, jj});
            }
        }
    }
    return di[ti][tj];
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[++n] = "#" + s + "#";
        m = sz(s);
        rep(j, 1, m) {
            if(isdigit(grid[n][j])) {
                int d = grid[n][j] - '0';
                k = max(k, d + 1);
                pi[d] = n;
                pj[d] = j;
            }
        }
    }
    rep(u, 0, k - 1) {
        rep(v, 0, k - 1) {
            dist[u][v] = bfs(pi[u], pj[u], pi[v], pj[v]);
        }
    }
    vector<int> perm(k);
    iota(rng(perm), 0);
    int ans = INF;
    do {
        if(perm[0] != 0) continue;
        int cur = 0;
        rep(i, 0, k - 2) {
            int u = perm[i], v = perm[i + 1];
            cur += dist[u][v];
        }
        cur += dist[perm[k - 1]][0];
        ans = min(ans, cur);
    } while(next_permutation(rng(perm)));
    cout << ans << endl;
    return 0;
}
