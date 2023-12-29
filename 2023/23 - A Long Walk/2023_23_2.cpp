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

const string SL = ">^<v";
const int DI[] = {0, -1, 0, 1};
const int DJ[] = {1, 0, -1, 0};
const int N = 222;
string grid[N];
bool vis[N][N];
int n, m, si, sj, ti, tj, ans;

void dfs(int i, int j, int len = 0) {
    if(grid[i][j] == '#' || vis[i][j]) return;
    if(i == ti && j == tj) {
        if(len > ans) {
            ans = len;
            cout << ans << endl;
        }
        return;
    }
    vis[i][j] = true;
    rep(d, 0, 3) {
        int ii = i + DI[d], jj = j + DJ[d];
        dfs(ii, jj, len + 1);
    }
    vis[i][j] = false;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[++n] = "#" + s + "#";
        m = sz(s);
    }
    grid[0] = string(m + 2, '#');
    grid[n + 1] = string(m + 2, '#');
    si = 1, sj = 2, ti = n, tj = m - 1;
    dfs(si, sj);
    return 0;
}
