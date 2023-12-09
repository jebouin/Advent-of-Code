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

const int N = 555;
int a[N][5][5];
bool has[N][5][5];
int n;

signed main() {
    freopen("input.txt", "r", stdin);
    vector<int> v;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    while(ss >> x) {
        v.pb(x);
        char c;
        ss >> c;
    }
    while(cin >> x) {
        n++;
        a[n][0][0] = x;
        rep(i, 0, 4) {
            rep(j, i == 0, 4) {
                cin >> a[n][i][j];
            }
        }
    }
    rall(x, v) {
        rep(k, 1, n) {
            rep(i, 0, 4) {
                rep(j, 0, 4) {
                    if(a[k][i][j] == x) {
                        has[k][i][j] = true;
                    }
                }
            }
            int sum = 0;
            bool win = false;
            rep(i, 0, 4) {
                bool ok = true, okk = true;
                rep(j, 0, 4) {
                    if(!has[k][i][j]) {
                        ok = false;
                        sum += a[k][i][j];
                    }
                    if(!has[k][j][i]) {
                        okk = false;
                    }
                }
                if(ok || okk) {
                    win = true;
                }
            }
            if(win) {
                int ans = sum * x;
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}
