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

signed main() {
    freopen("input.txt", "r", stdin);
    int ans = 0;
    string s;
    while(cin >> s) {
        int dep = 0, n = sz(s);
        bool in = false, out = false;
        rep(i, 0, n - 1) {
            char c = s[i];
            if(c == '[') {
                dep++;
            } else if(c == ']') {
                dep--;
            } else if(i + 3 < n && s[i] == s[i + 3] && s[i + 1] == s[i + 2] && s[i] != s[i + 1]) {
                if(dep > 0) {
                    in = true;
                } else {
                    out = true;
                }
            }
        }
        ans += out && !in;
    }
    cout << ans << endl;
    return 0;
}
