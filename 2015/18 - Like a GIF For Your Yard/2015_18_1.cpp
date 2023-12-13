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

const int N = 111;
string grid[N], gridd[N];
int n = 100;

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 1, n) {
        string s;
        cin >> s;
        grid[i] = "." + s + ".";
    }
    grid[0] = string(n + 2, '.');
    grid[n + 1] = grid[0];
    rep(_, 1, 100) {
        rep(i, 1, n) {
            gridd[i] = string(n + 2, '.');
            rep(j, 1, n) {
                int cnt = 0;
                rep(ii, i - 1, i + 1) {
                    rep(jj, j - 1, j + 1) {
                        if(i == ii && j == jj) continue;
                        cnt += grid[ii][jj] == '#';
                    }
                }
                gridd[i][j] = grid[i][j];
                if(grid[i][j] == '#' && (cnt < 2 || cnt > 3)) {
                    gridd[i][j] = '.';
                } else if(grid[i][j] == '.' && cnt == 3) {
                    gridd[i][j] = '#';
                }
            }
        }
        rep(i, 1, n) {
            grid[i] = gridd[i];
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, n) {
            ans += grid[i][j] == '#';
        }
    }
    cout << ans << endl;
    return 0;
}
