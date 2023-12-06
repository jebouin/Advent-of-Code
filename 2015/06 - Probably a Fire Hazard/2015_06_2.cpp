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

typedef long long ll;
using namespace std;

const int N = 1'111;
int a[N][N];
int n = 1000;

pair<int, int> getCoords(string s) {
    int pos = s.find(',');
    string l = s.substr(0, pos), r = s.substr(pos + 1);
    return {atoi(l.c_str()), atoi(r.c_str())};
}

signed main() {
    freopen("input.txt", "r", stdin);
    string type, w;
    while(cin >> type) {
        string value;
        if(type == "turn") {
            cin >> value;
        }
        cin >> w;
        pair<int, int> from = getCoords(w);
        cin >> w >> w;
        pair<int, int> to = getCoords(w);
        rep(i, from.fi, to.fi) {
            rep(j, from.se, to.se) {
                if(type == "toggle") {
                    a[i][j] += 2;
                } else if(value == "off") {
                    a[i][j] = max(0, a[i][j] - 1);
                } else if(value == "on") {
                    a[i][j] += 1;
                }
            }
        }
    }
    int ans = 0;
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            ans += a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
