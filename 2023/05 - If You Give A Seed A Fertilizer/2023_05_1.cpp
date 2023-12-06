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

const int INF = 1'000'000'000'000'000'000;
const int N = 22, K = 111, D = 111;
int from[N][K], to[N][K], len[N][K];
int seeds[D], ml[N];
int n, d;

signed main() {
    freopen("input.txt", "r", stdin);
    string w, line;
    getline(cin, line);
    stringstream ss(line);
    ss >> w;
    int x;
    while(ss >> x) {
        seeds[++d] = x;
    }
    getline(cin, line);
    while(getline(cin, line)) {
        n++;
        while(getline(cin, line)) {
            if(line == "") break;
            stringstream ss(line);
            ml[n]++;
            ss >> to[n][ml[n]] >> from[n][ml[n]] >> len[n][ml[n]];
        }
    }
    int ans = INF;
    rep(dd, 1, d) {
        int x = seeds[dd];
        rep(i, 1, n) {
            rep(j, 1, ml[i]) {
                int l = from[i][j], r = from[i][j] + len[i][j] - 1;
                if(x >= l && x <= r) {
                    x += to[i][j] - from[i][j];
                    break;
                }
            }
        }
        ans = min(ans, x);
    }
    cout << ans << endl;
    return 0;
}
