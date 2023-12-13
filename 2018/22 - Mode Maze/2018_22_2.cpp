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
#ifndef LOCAL
#define endl "\n"
#define cerr if(0) cerr
#endif
#define int long long

typedef long long ll;
using namespace std;

const int INF = 1'000'000'000;
const int N = 1'111, MOD = 20'183;
const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, -1, 0, 1};
int val[N][N], dist[N][N][3];

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    char c;
    int depth, tx, ty;
    cin >> s >> depth >> s >> tx >> c >> ty;
    rep(x, 0, N - 1) {
        rep(y, 0, N - 1) {
            if(x > 0 && y > 0) {
                val[x][y] = val[x - 1][y] * val[x][y - 1];
            } else if(x > 0) {
                val[x][0] = x * 16807;
            } else if(y > 0) {
                val[0][y] = y * 48271;
            }
            if(x == tx && y == ty) {
                val[x][y] = 0;
            }
            val[x][y] = (val[x][y] + depth) % MOD;
            fill(dist[x][y], dist[x][y] + 3, INF);
        }
    }
    dist[0][0][1] = 0;
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 1));
    while(sz(q)) {
        pair<pair<int, int>, int> pos = q.front();
        q.pop();
        int di = dist[pos.fi.fi][pos.fi.se][pos.se];
        rep(d, 0, 3) {
            int x = pos.fi.fi + DX[d], y = pos.fi.se + DY[d];
            if(x < 0 || y < 0 || x >= N || y >= N || val[x][y] % 3 == pos.se) continue;
            if(dist[x][y][pos.se] > di + 1) {
                dist[x][y][pos.se] = di + 1;
                q.push(make_pair(make_pair(x, y), pos.se));
            }
        }
        rep(nt, 0, 2) {
            int x = pos.fi.fi, y = pos.fi.se;
            if(nt == pos.se || val[x][y] % 3 == nt) continue;
            if(dist[x][y][nt] > dist[x][y][pos.se] + 7) {
                dist[x][y][nt] = dist[x][y][pos.se] + 7;
                q.push(make_pair(make_pair(x, y), nt));
            }
        }
    }
    int ans = dist[tx][ty][1];
    cout << ans << endl;
    return 0;
}
