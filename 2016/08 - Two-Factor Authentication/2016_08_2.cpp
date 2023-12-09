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

const int N = 11, M = 55;
string grid[N];
int n = 6, m = 50;

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 1, n) {
        grid[i] = string(m + 2, '.');
    }
    string w;
    while(cin >> w) {
        if(w == "rect") {
            cin >> w;
            int a = atoi(w.substr(0, w.find('x')).c_str());
            int b = atoi(w.substr(w.find('x') + 1).c_str());
            rep(i, 1, b) {
                rep(j, 1, a) {
                    grid[i][j] = '#';
                }
            }
        } else if(w == "rotate") {
            string type;
            cin >> type >> w;
            int a = atoi(w.substr(2).c_str()) + 1;
            cin >> w >> w;
            int b = atoi(w.c_str());
            while(b--) {
                if(type == "row") {
                    char c = grid[a][m];
                    rrep(j, 2, m) {
                        grid[a][j] = grid[a][j - 1];
                    }
                    grid[a][1] = c;
                } else {
                    char c = grid[n][a];
                    rrep(i, 2, n) {
                        grid[i][a] = grid[i - 1][a];
                    }
                    grid[1][a] = c;
                }
            }
        }
    }
    rep(i, 1, n) {
        cout << grid[i].substr(1, m) << endl;
    }
    return 0;
}
