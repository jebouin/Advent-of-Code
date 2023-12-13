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
string grid[N];
int n, m, ans;

void solve() {
    rep(ri, 1, n - 1) {
        bool ok = true;
        rep(d, 1, n) {
            int i1 = ri - d + 1, i2 = ri + d;
            rep(j, 1, m) {
                if(i1 >= 1 && i2 <= n && grid[i1][j] != grid[i2][j]) {
                    ok = false;
                }
            }
        }
        if(ok) {
            ans += 100 * ri;
            return;
        }
    }
    rep(rj, 1, m - 1) {
        bool ok = true;
        rep(d, 1, m) {
            int j1 = rj - d + 1, j2 = rj + d;
            rep(i, 1, n) {
                if(j1 >= 1 && j2 <= m && grid[i][j1] != grid[i][j2]) {
                    ok = false;
                }
            }
        }
        if(ok) {
            ans += rj;
            return;
        }
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(getline(cin, s)) {
        if(s == "") {
            solve();
            n = 0, m = 0;
        } else {
            n++;
            m = sz(s);
            grid[n] = " " + s + " ";
        }
    }
    solve();
    cout << ans << endl;
    return 0;
}

