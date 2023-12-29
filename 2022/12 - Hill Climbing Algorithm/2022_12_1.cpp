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
const int INF = 1'000'000;
const int N = 111;
string grid[N];
int dist[N][N];
int n, m;
int fi, fj, ti, tj;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[++n] = " " + s + " ";
        m = sz(s);
        rep(j, 1, m) {
            if(grid[n][j] == 'S') {
                fi = n, fj = j;
                grid[n][j] = 'a';
            } else if(grid[n][j] == 'E') {
                ti = n, tj = j;
                grid[n][j] = 'z';
            }
            dist[n][j] = INF;
        }
    }
    queue<pair<int, int> > q;
    q.push({fi, fj});
    dist[fi][fj] = 0;
    while(sz(q)) {
        pair<int, int> p = q.front();
        q.pop();
        rep(d, 0, 3) {
            int ii = p.fi + DI[d];
            int jj = p.se + DJ[d];
            if(ii < 1 || jj < 1 || ii > n || jj > m) continue;
            if((int)grid[ii][jj] - (int)grid[p.fi][p.se] > 1) continue;
            if(dist[ii][jj] > dist[p.fi][p.se] + 1) {
                dist[ii][jj] = dist[p.fi][p.se] + 1;
                q.push({ii, jj});
            }
        }
    }
    cout << dist[ti][tj] << endl;
    return 0;
}
