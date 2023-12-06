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

bool matches(string s) {
    int n = sz(s);
    bool hasPair = false, hasPal = false;
    rep(i, 0, n - 2) {
        rep(j, i + 2, n - 2) {
            if(s[i] == s[j] && s[i + 1] == s[j + 1]) {
                hasPair = true;
            }
        }
    }
    rep(i, 0, n - 3) {
        if(s[i] == s[i + 2]) {
            hasPal = true;
        }
    }
    return hasPair && hasPal;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    int ans = 0;
    while(cin >> s) {
        ans += matches(s);
    }
    cout << ans << endl;
    return 0;
}
