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
    int len = 35651584;
    string s;
    cin >> s;
    while(sz(s) < len) {
        string t = s;
        rep(i, 0, sz(s) - 1) {
            s[i] = '0' + '1' - s[i];
        }
        reverse(rng(s));
        t += "0" + s;
        s = t;
    }
    s = s.substr(0, len);
    while(sz(s) % 2 == 0) {
        string t(sz(s) / 2, '0');
        rep(i, 0, sz(s) / 2 - 1) {
            t[i] = '0' + (s[2 * i] == s[2 * i + 1]);
        }
        s = t;
    }
    cout << s << endl;
    return 0;
}
