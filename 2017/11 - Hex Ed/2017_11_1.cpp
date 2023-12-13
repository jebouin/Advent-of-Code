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
    string s;
    vector<string> v;
    cin >> s;
    int p = 0;
    do {
        int np = s.find(',', p);
        if(np == (int)string::npos) {
            np = sz(s);
        }
        string dir = s.substr(p, np - p);
        v.pb(dir);
        p = np + 1;
    } while(p < sz(s));
    int i = 0, j = 0;
    rall(s, v) {
        if(s == "n") {
            i--;
        } else if(s == "ne") {
            j++;
        } else if(s == "se") {
            i++; j++;
        } else if(s == "s") {
            i++;
        } else if(s == "sw") {
            j--;
        } else if(s == "nw") {
            i--; j--;
        }
    }
    int ans = 0;
    if(i < 0 && j < 0) {
        ans += min(-i, -j);
        i += ans; j += ans;
    } else if(i > 0 && j > 0) {
        ans += min(i, j);
        i -= ans; j -= ans;
    }
    ans += abs(i) + abs(j);
    cout << ans << endl;
    return 0;
}
