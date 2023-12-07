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

const int N = 1'111, K = 11'111;
int claim[N][N], ok[K];
int n = 1'000;

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        int id, x, y, w, h;
        char c;
        ss >> c >> id >> c >> x >> c >> y >> c >> w >> c >> h;
        ok[id] = true;
        rep(i, x, x + w - 1) {
            rep(j, y, y + h - 1) {
                if(claim[i][j] > 0) {
                    ok[claim[i][j]] = false;
                    ok[id] = false;
                }
                claim[i][j] = id;
            }
        }
    }
    rep(k, 1, K - 1) {
        if(ok[k]) {
            cout << k << endl;
            return 0;
        }
    }
    return 0;
}
