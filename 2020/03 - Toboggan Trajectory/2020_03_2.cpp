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

const int N = 555, M = 55;
string grid[N];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[n++] = s;
        m = sz(s);
    }
    vector<pair<int, int> > slopes = {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2},
    };
    int ans = 1;
    rall(p, slopes) {
        int i = 0, j = 0, cnt = 0;
        while(i < n) {
            cnt += grid[i][j % m] == '#';
            i += p.se;
            j += p.fi;
        }
        ans *= cnt;
    }
    cout << ans << endl;
    return 0;
}
