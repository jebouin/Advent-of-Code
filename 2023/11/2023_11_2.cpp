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

const int N = 222, K = 1111;
string grid[N];
int cntr[N], cntc[N], gi[K], gj[K];
int dist[K][K];
int n = 140, ex = 1'000'000, k;

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 1, n) {
        string s;
        cin >> s;
        grid[i] = " " + s + " ";
        rep(j, 1, n) {
            if(grid[i][j] == '#') {
                cntr[i]++;
                cntc[j]++;
                k++;
                gi[k] = i;
                gj[k] = j;
            }
        }
    }
    int ans = 0;
    rep(x, 1, k) {
        rep(y, x + 1, k) {
            int add = 0;
            int fi = gi[x], fj = gj[x];
            int ti = gi[y], tj = gj[y];
            rep(i, min(fi, ti), max(fi, ti)) {
                add += cntr[i] == 0 ? ex : 1;
            }
            rep(j, min(fj, tj), max(fj, tj)) {
                add += cntc[j] == 0 ? ex : 1;
            }
            add -= 2;
            ans += add;
        }
    }
    cout << ans << endl;
    return 0;
}

