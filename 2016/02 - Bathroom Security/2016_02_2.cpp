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

string pad[] = {
    "  1  ",
    " 123 ",
    "56789",
    " ABC ",
    "  D  ",
};
int n = 5, m = 5;

signed main() {
    freopen("input.txt", "r", stdin);
    string ans, line;
    while(getline(cin, line)) {
        int i = 2, j = 0;
        rall(c, line) {
            int pi = i, pj = j;
            if(c == 'U') i--;
            if(c == 'D') i++;
            if(c == 'L') j--;
            if(c == 'R') j++;
            if(i < 0 || j < 0 || i >= n || j >= m || pad[i][j] == ' ') {
                i = pi;
                j = pj;
            }
        }
        ans += pad[i][j];
    }
    cout << ans << endl;
    return 0;
}
