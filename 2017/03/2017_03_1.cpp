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

signed main() {
    freopen("input.txt", "r", stdin);
    int x = 0, y = 0, dir = 0, k = 1, n;
    cin >> n;
    n--;
    while(1) {
        for(int i = 0; i < k; i++) {
            if(n == 0) {
                cout << abs(x) + abs(y) << endl;
                return 0;
            }
            x += DX[dir];
            y += DY[dir];
            n--;
        }
        dir = (dir + 1) % 4;
        if(dir % 2 == 0) {
            k++;
        }
    }
    return 0;
}
