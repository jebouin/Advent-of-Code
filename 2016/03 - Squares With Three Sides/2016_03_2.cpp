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

vector<int> cols[3];

signed main() {
    freopen("input.txt", "r", stdin);
    int ans = 0, x, y, z;
    while(cin >> x) {
        cin >> y >> z;
        cols[0].pb(x);
        cols[1].pb(y);
        cols[2].pb(z);
    }
    vector<int> all;
    rep(i, 0, 2) {
        all.insert(all.end(), rng(cols[i]));
    }
    rep(i, 0, sz(all) / 3) {
        int x = all[3 * i], y = all[3 * i + 1], z = all[3 * i + 2];
        if(x > y) swap(x, y);
        if(x > z) swap(x, z);
        if(y > z) swap(y, z);
        ans += x + y > z;
    }
    cout << ans << endl;
    return 0;
}
