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
int sum[N][N];
int n = 300;

signed main() {
    freopen("input.txt", "r", stdin);
    int bx = 1, by = 1, bs, best = -1'000'000'000;
    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            int id = x + 10;
            int p = id * y;
            p += 1718;
            p *= id;
            p = (p / 100) % 10;
            p -= 5;
            sum[y][x] = p + sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1];
        }
    }
    for(int s = 1; s <= n; s++) {
        for(int y = s; y <= n; y++) {
            for(int x = s; x <= n; x++) {
                int total = sum[y][x] - sum[y - s][x] - sum[y][x - s] + sum[y - s][x - s];
                if(total > best) {
                    best = total;
                    bx = x;
                    by = y;
                    bs = s;
                }
            }
        }
    }
    cout << bx - bs + 1 << "," << by - bs + 1 << "," << bs << endl;
    return 0;
}
