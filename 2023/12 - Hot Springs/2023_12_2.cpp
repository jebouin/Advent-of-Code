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

const int N = 111, K = 111;
int dp[N][N][N];
int n, k;

signed main() {
    freopen("input.txt", "r", stdin);
    string s, t;
    int ans = 0;
    while(cin >> s) {
        cin >> t;
        s = s + "?" + s + "?" + s + "?" + s + "?" + s;
        t = t + "," + t + "," + t + "," + t + "," + t;
        vector<int> v;
        int x = 0;
        rall(d, t) {
            if(d == ',') {
                v.pb(x);
                x = 0;
            } else {
                x = 10 * x + d - '0';
            }
        }
        if(x > 0) {
            v.pb(x);
        }
        s += ".";
        n = sz(s);
        k = sz(v);
        rep(i, 0, n) {
            rep(c, 0, n) {
                rep(j, 0, k) {
                    dp[i][c][j] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        rep(i, 0, n - 1) {
            rep(c, 0, n) {
                rep(j, 0, k) {
                    if(s[i] == '?') {
                        // add '.'
                        if(j < k && c == v[j]) {
                            dp[i + 1][0][j + 1] += dp[i][c][j];
                        } else if(c == 0) {
                            dp[i + 1][0][j] += dp[i][0][j];
                        }
                        // add '#'
                        dp[i + 1][c + 1][j] += dp[i][c][j];
                    } else if(s[i] == '.') {
                        if(j < k && c == v[j]) {
                            dp[i + 1][0][j + 1] += dp[i][c][j];
                        } else if(c == 0) {
                            dp[i + 1][0][j] += dp[i][0][j];
                        }
                    } else if(s[i] == '#') {
                        dp[i + 1][c + 1][j] += dp[i][c][j];
                    }
                }
            }
        }
        int add = dp[n][0][k];
        ans += add;
    }
    cout << ans << endl;
    return 0;
}
