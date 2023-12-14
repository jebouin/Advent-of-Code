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

const int N = 1'111;
string grid[N], gridd[N];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[++n] = "." + s + ".";
        m = sz(s);
    }
    grid[0] = string(m + 2, '.');
    grid[n + 1] = grid[0];
    while(1) {
        bool ch = false;
        copy(grid + 1, grid + n + 1, gridd + 1);
        rep(i, 1, n) {
            rep(j, 1, m) {
                if(grid[i][j] == '.') continue;
                int cnt = 0;
                rep(ii, i - 1, i + 1) {
                    rep(jj, j - 1, j + 1) {
                        if(ii == i && jj == j) continue;
                        cnt += grid[ii][jj] == '#';
                    }
                }
                if(grid[i][j] == 'L' && cnt == 0) {
                    gridd[i][j] = '#';
                    ch = true;
                } else if(grid[i][j] == '#' && cnt >= 4) {
                    gridd[i][j] = 'L';
                    ch = true;
                }
            }
        }
        copy(gridd + 1, gridd + n + 1, grid + 1);
        if(!ch) break;
    }
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            ans += grid[i][j] == '#';
        }
    }
    cout << ans << endl;
    return 0;
}
