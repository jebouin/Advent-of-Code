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

const int N = 555;
int grid[N][N], visible[N][N];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        n++;
        m = sz(s);
        rep(j, 1, m) {
            grid[n][j] = s[j - 1] - '0';
        }
    }
    rep(i, 1, n) {
        int cur = -1;
        rep(j, 1, m) {
            if(grid[i][j] > cur) {
                visible[i][j] = true;
                cur = grid[i][j];
            }
        }
        cur = -1;
        rrep(j, 1, m) {
            if(grid[i][j] > cur) {
                visible[i][j] = true;
                cur = grid[i][j];
            }
        }
    }
    rep(j, 1, m) {
        int cur = -1;
        rep(i, 1, n) {
            if(grid[i][j] > cur) {
                visible[i][j] = true;
                cur = grid[i][j];
            }
        }
        cur = -1;
        rrep(i, 1, n) {
            if(grid[i][j] > cur) {
                visible[i][j] = true;
                cur = grid[i][j];
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            ans += visible[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
