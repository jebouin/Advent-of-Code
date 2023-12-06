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

const int N = 1111;
string grid[N];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[++n] = " " + s;
        m = sz(s);
    }
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(grid[i][j] == '.') continue;
            set<pair<int, int> > st;
            rep(ii, 1, n) {
                rep(jj, 1, m) {
                    if((ii == i && jj == j) || grid[ii][jj] == '.') continue;
                    int di = ii - i, dj = jj - j;
                    int g = __gcd(abs(di), abs(dj));
                    di /= g, dj /= g;
                    st.insert(make_pair(di, dj));
                }
            }
            ans = max(ans, sz(st));
        }
    }
    cout << ans << endl;
    return 0;
}
