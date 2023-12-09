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
    string s;
    while(cin >> s) {
        int dep = 0, n = sz(s);
        set<string> in, out;
        rep(i, 0, n - 1) {
            char c = s[i];
            if(c == '[') {
                dep++;
            } else if(c == ']') {
                dep--;
            } else if(i + 2 < n && s[i] == s[i + 2] && s[i] != s[i + 1]) {
                string sub = s.substr(i, 3);
                if(dep > 0) {
                    in.insert(sub);
                } else {
                    out.insert(sub);
                }
            }
        }
        rall(s, out) {
            string need = string(1, s[1]) + string(1, s[0]) + string(1, s[1]);
            if(in.find(need) != in.end()) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
