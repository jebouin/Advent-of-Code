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
    vector<int> v;
    v.pb(3);
    v.pb(7);
    int a = 0, b = 1;
    string s;
    cin >> s;
    rep(i, 0, 30'000'000) {
        int sum = v[a] + v[b];
        vector<int> nv;
        if(!sum) {
            v.pb(0);
        } else {
            while(sum) {
                nv.pb(sum % 10);
                sum /= 10;
            }
            reverse(rng(nv));
            v.insert(v.end(), rng(nv));
        }
        a = (a + 1 + v[a]) % sz(v);
        b = (b + 1 + v[b]) % sz(v);
    }
    rep(i, 0, sz(v) - sz(s) + 1) {
        bool ok = true;
        rep(j, 0, sz(s) - 1) {
            if(s[j] - '0' != v[i + j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
