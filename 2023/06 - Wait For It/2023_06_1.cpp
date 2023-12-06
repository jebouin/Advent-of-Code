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

const int N = 11;
int t[N], d[N];
int n = 4;

signed main() {
    freopen("input.txt", "r", stdin);
    string w;
    cin >> w;
    rep(i, 1, n) {
        cin >> t[i];
    }
    cin >> w;
    rep(i, 1, n) {
        cin >> d[i];
    }
    int ans = 1;
    rep(i, 1, n) {
        int cnt = 0;
        rep(h, 0, t[i]) {
            int cur = h * (t[i] - h);
            cnt += cur > d[i];
        }
        ans *= cnt;
    }
    cout << ans << endl;
    return 0;
}
