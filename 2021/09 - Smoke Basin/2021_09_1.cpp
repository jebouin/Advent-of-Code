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

const int DI[] = {1, 0, -1, 0};
const int DJ[] = {0, -1, 0, 1};
const int N = 111;
string grid[N];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        m = sz(s);
        grid[++n] = " " + s + " ";
    }
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            int cnt = 0;
            rep(d, 0, 3) {
                int ii = i + DI[d];
                int jj = j + DJ[d];
                if(ii < 1 || jj < 1 || ii > n || jj > m) continue;
                cnt += grid[ii][jj] <= grid[i][j];
            }
            if(cnt > 0) continue;
            ans += grid[i][j] - '0' + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
