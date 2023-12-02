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

typedef long long ll;
using namespace std;

signed main() {
    freopen("input.txt", "r", stdin);
    int ans = 0;
    rep(i, 1, 100) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        set<char> st1(rng(s1)), st2(rng(s2)), st3(rng(s3));
        rall(c, st1) {
            if(st2.find(c) != st2.end() && st3.find(c) != st3.end()) {
                ans += c >= 'a' && c <= 'z' ? c - 'a' + 1 : c - 'A' + 27;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
