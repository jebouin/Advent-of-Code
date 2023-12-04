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

const int N = 155, K = 111'111;
string grid[N];
int n = 140, k = 0;

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 1, n) {
        string s;
        cin >> s;
        grid[i] = "." + s + ".";
    }
    grid[0] = string(n + 2, '.');
    grid[n + 1] = grid[0];
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, n) {
            if(isdigit(grid[i][j]) && !isdigit(grid[i][j - 1])) {
                int value = grid[i][j] - '0';
                int len = 1;
                while(isdigit(grid[i][j + len])) {
                    value = 10 * value + grid[i][j + len] - '0';
                    len++;
                }
                bool ok = false;
                rep(ii, i - 1, i + 1) {
                    rep(jj, j - 1, j + len) {
                        if(grid[ii][jj] != '.' && !isdigit(grid[ii][jj])) {
                            ok = true;
                        }
                    }
                }
                if(ok) {
                    ans += value;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
