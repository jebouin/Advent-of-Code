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

const int N = 111;
int a[N][N][N];
int n = 6, m = 25, k;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    k = s.size() / n / m;
    int lay = 1, mini = 1e9;
    rep(c, 1, k) {
        int cur = 0;
        rep(i, 1, n) {
            rep(j, 1, m) {
                a[c][i][j] = s[(c - 1) * n * m + (i - 1) * m + j - 1] - '0';
                cur += a[c][i][j] == 0;
            }
        }
        if(cur < mini) {
            mini = cur;
            lay = c;
        }
    }
    int n1 = 0, n2 = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            n1 += a[lay][i][j] == 1;
            n2 += a[lay][i][j] == 2;
        }
    }
    cout << n1 * n2 << endl;
    return 0;
}
