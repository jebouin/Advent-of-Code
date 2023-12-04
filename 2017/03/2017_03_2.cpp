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

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, -1, 0, 1};
const int S = 1'000;
int grid[S][S];

signed main() {
    freopen("input.txt", "r", stdin);
    int x = S / 2, y = S / 2, dir = 0, k = 1, n;
    cin >> n;
    n--;
    grid[y][x] = 1;
    while(1) {
        for(int i = 0; i < k; i++) {
            x += DX[dir];
            y += DY[dir];
            rep(xx, x - 1, x + 1) {
                rep(yy, y - 1, y + 1) {
                    if(xx == x && yy == y) continue;
                    grid[y][x] += grid[yy][xx];
                }
            }
            if(grid[y][x] > n) {
                cout << grid[y][x] << endl;
                return 0;
            }
        }
        dir = (dir + 1) % 4;
        if(dir % 2 == 0) {
            k++;
        }
    }
    return 0;
}
