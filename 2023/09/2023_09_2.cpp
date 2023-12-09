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
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        int x;
        vector<int> v;
        while(ss >> x) {
            v.pb(x);
        }
        reverse(rng(v));
        vector<vector<int> > all(1, v);
        while(1) {
            vector<int> vv, v = all.back();
            int n = sz(v);
            bool done = true;
            rep(i, 1, n - 1) {
                int diff = v[i] - v[i - 1];
                if(diff) {
                    done = false;
                }
                vv.pb(diff);
            }
            all.pb(vv);
            if(done) break;
        }
        int add = 0, n = sz(all);
        rrep(i, 0, n - 1) {
            add += all[i].back();
        }
        ans += add;
    }
    cout << ans << endl;
    return 0;
}
