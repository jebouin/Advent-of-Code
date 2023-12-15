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

const int N = 1'111;
int l[N], r[N];
int n;

bool test(int x) {
    rep(i, 1, n) {
        if(x >= l[i] && x <= r[i]) {
            return false;
        }
    }
    return true;
}

signed main() {
    freopen("input.txt", "r", stdin);
    int x;
    while(cin >> x) {
        l[++n] = x;
        char c;
        cin >> c >> x;
        r[n] = x;
    }
    int ans = 1'000'000'000;
    rep(i, 1, n) { 
        int x = l[i] - 1;
        if(x < 0) continue;
        if(test(x)) {
            ans = min(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}
