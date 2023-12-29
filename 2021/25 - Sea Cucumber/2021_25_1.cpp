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

const int N = 555;
string grid[N];
bool mov[N][N];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        n++;
        grid[n] = " " + s + " ";
        m = sz(s);
    }
    int ans = 0;
    while(1) {
        ans++;
        bool ch = false;
        rep(i, 1, n) {
            fill(mov[i] + 1, mov[i] + m + 1, false);
        }
        rep(i, 1, n) {
            rep(j, 1, m) {
                if(grid[i][j] != '>') continue;
                int jj = j == m ? 1 : j + 1;
                if(grid[i][jj] == '.') {
                    mov[i][j] = true;
                    ch = true;
                }
            }
        }
        rep(i, 1, n) {
            rep(j, 1, m) {
                int jj = j == m ? 1 : j + 1;
                if(mov[i][j]) {
                    grid[i][j] = '.';
                    grid[i][jj] = '>';
                }
            }
        }
        rep(i, 1, n) {
            fill(mov[i] + 1, mov[i] + m + 1, false);
        }
        rep(i, 1, n) {
            int ii = i == n ? 1 : i + 1;
            rep(j, 1, m) {
                if(grid[i][j] != 'v') continue;
                if(grid[ii][j] == '.') {
                    mov[i][j] = true;
                    ch = true;
                }
            }
        }
        rep(i, 1, n) {
            int ii = i == n ? 1 : i + 1;
            rep(j, 1, m) {
                if(mov[i][j]) {
                    grid[i][j] = '.';
                    grid[ii][j] = 'v';
                }
            }
        }
        if(!ch) {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}
