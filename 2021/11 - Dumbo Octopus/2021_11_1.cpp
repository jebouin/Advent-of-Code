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
bool fl[N][N];
int n, m, ans;

void inc(int i, int j) {
    if(fl[i][j]) return;
    if(grid[i][j] < '9') {
        grid[i][j]++;
        return;
    }
    fl[i][j] = true;
    grid[i][j] = '0';
    ans++;
    rep(ii, max(i - 1, 1ll), min(i + 1, n)) {
        rep(jj, max(j - 1, 1ll), min(j + 1, m)) {
            inc(ii, jj);
        }
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        m = sz(s);
        ++n;
        grid[n] = " " + s + " ";
    }
    rep(_, 1, 100) {
        rep(i, 1, n) {
            rep(j, 1, m) {
                fl[i][j] = false;
            }
        }
        rep(i, 1, n) {
            rep(j, 1, m) {
                inc(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
