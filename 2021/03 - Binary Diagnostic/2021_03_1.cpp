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
    int m = 0, n = 0;
    vector<int> v;
    string s;
    while(cin >> s) {
        m = sz(s);
        while(sz(v) < m) {
            v.pb(0);
        }
        rep(j, 0, m - 1) {
            v[j] += s[j] == '1';
        }
        n++;
    }
    int x = 0, y = 0;
    rep(j, 0, m - 1) {
        int p = 1 << (m - 1 - j);
        if(2 * v[j] > n) {
            x += p;
        } else {
            y += p;
        }
    }
    int ans = x * y;
    cout << ans << endl;
    return 0;
}
