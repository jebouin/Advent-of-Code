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

const int DX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int N = 111;
string grid[N], grid2[N];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        m = sz(s);
        n++;
        grid[n] = " " + s + " ";
        grid2[n] = string(52, '.');
    }
    rep(o, 1, 10) {
        rep(i, 1, n) {
            rep(j, 1, m) {
                grid2[i][j] = grid[i][j];
                int tree = 0, lumb = 0;
                rep(d, 0, 7) {
                    int ii = i + DX[d];
                    int jj = j + DY[d];
                    tree += grid[ii][jj] == '|';
                    lumb += grid[ii][jj] == '#';
                }
                if(grid[i][j] == '.' && tree >= 3) {
                    grid2[i][j] = '|';
                } else if(grid[i][j] == '|' && lumb >= 3) {
                    grid2[i][j] = '#';
                } else if(grid[i][j] == '#' && !(tree >= 1 && lumb >= 1)) {
                    grid2[i][j] = '.';
                }
            }
        }
        rep(i, 1, n) {
            grid[i] = grid2[i];
        }
    }
    int x = 0, y = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            x += grid[i][j] == '|';
            y += grid[i][j] == '#';
        }
    }
    cout << x * y << endl;
    return 0;
}
