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

int m;

int solve(bool rule, vector<string> all) {
    int ans = 0;
    rep(i, 0, m - 1) {
        if(sz(all) > 1) {
            int n = sz(all);
            int cnt = 0;
            rall(s, all) {
                cnt += s[i] == '1';
            }
            char need = (cnt * 2 != n && (cnt * 2 > n || cnt * 2 == n) ^ rule) || (cnt * 2 == n && !rule) ? '1' : '0';
            vector<string> rem;
            rall(s, all) {
                if(s[i] == need) {
                    rem.pb(s);
                }
            }
            all = rem;
            ans = 2 * ans + (need == '1');
        } else {
            ans = 2 * ans + (all[0][i] == '1');
        }
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    vector<string> all;
    while(cin >> s) {
        all.pb(s);
        m = sz(s);
    }
    int x = solve(false, all), y = solve(true, all);
    int ans = x * y;
    cout << ans << endl;
    return 0;
}
