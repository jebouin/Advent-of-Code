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

int solve(string s) {
    int x = 0;
    rall(c, s) {
        x += c;
        x = (x * 17) % 256;
    }
    return x;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int pos = 0, ans = 0;
    while(pos < sz(s)) {
        int np = s.find(",", pos);
        if(np == (int)string::npos) np = sz(s);
        string sub = s.substr(pos, np - pos);
        ans += solve(sub);
        pos = np + 1;
    }
    cout << ans << endl;
    return 0;
}
