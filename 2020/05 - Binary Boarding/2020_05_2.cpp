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
    set<int> st;
    while(cin >> s) {
        int i = 0;
        rep(b, 0, 6) {
            if(s[b] == 'B') {
                i |= (1 << (6 - b));
            }
        }
        int j = 0;
        rep(b, 0, 2) {
            if(s[7 + b] == 'R') {
                j |= (1 << (2 - b));
            }
        }
        int cur = i * 8 + j;
        st.insert(cur);
    }
    rep(x, 0, 128 * 8 - 1) {
        if(st.find(x) != st.end() || st.find(x - 1) == st.end() || st.find(x + 1) == st.end()) continue;
        int i = x / 8;
        if(i == 0 || i == 127) continue;
        cout << x << endl;
        return 0;
    }
    return 0;
}
