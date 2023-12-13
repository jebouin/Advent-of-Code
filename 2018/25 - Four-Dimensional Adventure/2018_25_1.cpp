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
int x[N], y[N], z[N], w[N], c[N], cnt[N];
int n;

signed main() {
    freopen("input.txt", "r", stdin);
    int num;
    char _;
    while(cin >> num) {
        x[++n] = num;
        cin >> _ >> y[n] >> _ >> z[n] >> _ >> w[n];
        c[n] = n;
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            if(c[i] == c[j]) continue;
            int d = abs(x[i] - x[j]) + abs(y[i] - y[j]) + abs(z[i] - z[j]) + abs(w[i] - w[j]);
            if(d > 3) continue;
            int from = c[j], to = c[i];
            rep(k, 1, n) {
                if(c[k] == from) {
                    c[k] = to;
                }
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        if(cnt[c[i]] == 0) {
            ans++;
        }
        cnt[c[i]]++;
    }
    cout << ans << endl;
    return 0;
}

