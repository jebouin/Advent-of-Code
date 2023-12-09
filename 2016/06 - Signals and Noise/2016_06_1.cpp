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

const int M = 111;
int cnt[M][26];
int m;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        m = sz(s);
        rep(j, 1, m) {
            cnt[j][s[j - 1] - 'a']++;
        }
    }
    string ans;
    rep(j, 1, m) {
        int maxi = 0, best = 0;
        rep(x, 0, 25) {
            if(cnt[j][x] > maxi) {
                maxi = cnt[j][x];
                best = x;
            }
        }
        ans += string(1, best + 'a');
    }
    cout << ans << endl;
    return 0;
}
