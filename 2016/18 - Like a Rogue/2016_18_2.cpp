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
    string s, t;
    cin >> s;
    int n = sz(s);
    s = "." + s + ".";
    int ans = 0;
    rep(i, 1, n) {
        ans += s[i] == '.';
    }
    rep(i, 1, 399999) {
        string t(n + 2, '.');
        rep(j, 1, n) {
            string sub = s.substr(j - 1, 3);
            if(sub == "^^." || sub == ".^^" || sub == "^.." || sub == "..^") {
                t[j] = '^';
            }
        }
        s = t;
        rep(i, 1, n) {
            ans += s[i] == '.';
        }
    }
    cout << ans << endl;
    return 0;
}
