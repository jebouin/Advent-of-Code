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

const int N = 333;
int a[N][N];
int n = 300;

signed main() {
    freopen("input.txt", "r", stdin);
    int bx = 1, by = 1, best = -1'000'000'000;
    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            int id = x + 10;
            int p = id * y;
            p += 1718;
            p *= id;
            p = (p / 100) % 10;
            p -= 5;
            a[y][x] = p;
        }
    }
    for(int y = 1; y <= n - 2; y++) {
        for(int x = 1; x <= n - 2; x++) {
            int total = 0;
            rep(yy, y, y + 2) {
                rep(xx, x, x + 2) {
                    total += a[yy][xx];
                }
            }
            if(total > best) {
                best = total;
                bx = x;
                by = y;
            }
        }
    }
    cout << bx << "," << by << endl;
    return 0;
}
