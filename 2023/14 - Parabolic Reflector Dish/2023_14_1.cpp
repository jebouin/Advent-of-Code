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

const int N = 111;
string grid[N];
int n;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[++n] = "#" + s + "#";
    }
    while(1) {
        bool ch = false;
        rep(i, 1, n) {
            rep(j, 1, n) {
                if(grid[i][j] != 'O') continue;
                if(grid[i - 1][j] == '.') {
                    grid[i - 1][j] = 'O';
                    grid[i][j] = '.';
                    ch = true;
                }
            }
        }
        if(!ch) break;
    }
    int ans = 0;
    rep(i, 1, n) {
        int mult = n - i + 1;
        int add = 0;
        rep(j, 1, n) {
            add += grid[i][j] == 'O';
        }
        ans += add * mult;
    }
    cout << ans << endl;
    return 0;
}
