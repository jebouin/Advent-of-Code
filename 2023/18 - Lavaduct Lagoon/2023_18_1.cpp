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
const int N = 1'000, A = 500;
int grid[N][N];
int ans = 0;

void bfs(int i, int j, int col) {
    queue<pair<int, int> > q;
    q.push({i, j});
    while(sz(q)) {
        auto p = q.front();
        q.pop();
        if(grid[p.fi][p.se] != col) {
            grid[p.fi][p.se] = col;
            ans++;
            rep(d, 0, 3) {
                int ii = p.fi + DI[d];
                int jj = p.se + DJ[d];
                if(ii < 0 || jj < 0 || ii >= N || jj >= N || grid[ii][jj]) {
                    continue;
                }
                q.push({ii, jj});
            }
        }
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    char dir;
    int dist;
    string s;
    int i = A, j = A;
    while(cin >> dir) {
        int ni = i, nj = j;
        cin >> dist >> s;
        if(dir == 'L') {
            nj += dist;
        } else if(dir == 'R') {
            nj -= dist;
        } else if(dir == 'U') {
            ni -= dist;
        } else if(dir == 'D') {
            ni += dist;
        }
        while(i != ni || j != nj) {
            grid[i][j] = 2;
            if(i < ni) i++;
            if(j < nj) j++;
            if(i > ni) i--;
            if(j > nj) j--;
        }
        grid[ni][nj] = 2;
    }
    bfs(0, 0, -1);
    ans = 0;
    rep(i, 0, N - 1) {
        rep(j, 0, N - 1) {
            if(grid[i][j] == 2) ans++;
            if(grid[i][j]) continue;
            bfs(i, j, 1);
        }
    }
    cout << ans << endl;
    return 0;
}
