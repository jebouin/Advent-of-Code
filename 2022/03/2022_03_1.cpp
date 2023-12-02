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

typedef long long ll;
using namespace std;

signed main() {
    freopen("input.txt", "r", stdin);
    int ans = 0;
    string s;
    while(cin >> s) {
        int n = sz(s);
        set<char> stl, str;
        rep(i, 1, n / 2) {
            stl.insert(s[i - 1]);
        }
        rep(i, 1, n / 2) {
            str.insert(s[n / 2 + i - 1]);
        }
        rall(c, stl) {
            if(str.find(c) != str.end()) {
                ans += c >= 'a' && c <= 'z' ? c - 'a' + 1 : c - 'A' + 27;
            }
        }
    }
    return 0;
}
