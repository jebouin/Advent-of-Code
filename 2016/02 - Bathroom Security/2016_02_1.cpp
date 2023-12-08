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

string pad[] = {"123", "456", "789"};
int n = 3, m = 3;

signed main() {
    freopen("input.txt", "r", stdin);
    string ans, line;
    while(getline(cin, line)) {
        int i = 1, j = 1;
        rall(c, line) {
            if(c == 'U') i = max(0, i - 1);
            if(c == 'D') i = min(n - 1, i + 1);
            if(c == 'L') j = max(0, j - 1);
            if(c == 'R') j = min(m - 1, j + 1);
        }
        ans += pad[i][j];
    }
    cout << ans << endl;
    return 0;
}
