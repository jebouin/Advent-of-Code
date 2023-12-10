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

const int DJ[] = {1, 0, -1, 0};
const int DI[] = {0, -1, 0, 1};
const int N = 222;
string grid[N];
int n, m;
string sym = "|-LJ7F";
vector<int> ne[6] = {
    {-1, 3, -1, 1},
    {2, -1, 0, -1},
    {1, 0, -1, -1},
    {-1, 2, 1, -1},
    {-1, -1, 3, 2},
    {3, -1, -1, 0}
};
int isl[N][N];

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[++n] = " " + s + " ";
        m = sz(s);
    }
    int si = 1, sj = 1, dir = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(grid[i][j] == 'S') {
                rep(k, 0, 5) {
                    bool ok = true;
                    rep(d, 0, 3) {
                        if(ne[k][d] == -1) continue;
                        int ii = i + DI[d];
                        int jj = j + DJ[d];
                        if(ii < 1 || jj < 1 || ii > n || jj > m) continue;
                        char c = grid[ii][jj];
                        int kk = sym.find(c);
                        if(ne[kk][(d + 2) % 4] == -1) {
                            ok = false;
                        }
                    }
                    if(ok) {
                        grid[i][j] = sym[k];
                        break;
                    }
                }
                si = i, sj = j;
            }
        }
    }
    int i = si, j = sj, len = 0;
    do {
        i += DI[dir];
        j += DJ[dir];
        int id = sym.find(grid[i][j]);
        dir = ne[id][(dir + 2) % 4];
        len++;
        isl[i][j] = true;
    } while(i != si || j != sj);
    cout << len / 2 << endl;
    return 0;
}
