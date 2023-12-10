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
bool basin[N][N];
int n, m;

int dfs(int i, int j) {
    int ans = 1;
    basin[i][j] = false;
    rep(d, 0, 3) {
        int ii = i + DI[d];
        int jj = j + DJ[d];
        if(basin[ii][jj]) {
            ans += dfs(ii, jj);
        }
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        m = sz(s);
        grid[++n] = " " + s + " ";
    }
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(grid[i][j] != '9') {
                basin[i][j] = true;
            }
        }
    }
    vector<int> v;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(!basin[i][j]) continue;
            int cnt = dfs(i, j);
            v.pb(cnt);
        }
    }
    sort(rng(v), std::greater<int>());
    int ans = v[0] * v[1] * v[2];
    cout << ans << endl;
    return 0;
}
