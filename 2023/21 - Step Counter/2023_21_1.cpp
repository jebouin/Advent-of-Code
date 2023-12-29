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

const int DI[] = {0, 1, 0, -1};
const int DJ[] = {1, 0, -1, 0};
const int N = 222;
string grid[N];
bool a[N][N], b[N][N];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    int si = 0, sj = 0;
    while(cin >> s) {
        n++;
        grid[n] = "#" + s + "#";
        m = sz(s);
        rep(j, 1, m) {
            if(s[j - 1] == 'S') {
                si = n;
                sj = j;
                s[j] = '.';
            }
        }
    }
    grid[0] = string(m + 2, '#');
    grid[n + 1] = string(m + 2, '#');
    a[si][sj] = true;
    int cnt = 64;
    rep(o, 1, cnt) {
        rep(i, 1, n) {
            rep(j, 1, m) {
                b[i][j] = 0;
            }
        }
        rep(i, 1, n) {
            rep(j, 1, m) {
                if(!a[i][j]) continue;
                rep(d, 0, 3) {
                    int ii = i + DI[d], jj = j + DJ[d];
                    if(grid[ii][jj] == '#') continue;
                    b[ii][jj] = true;
                }
            }
        }
        rep(i, 1, n) {
            rep(j, 1, m) {
                a[i][j] = b[i][j];
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            ans += a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
