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

const int N = 30, ORIG = 10;
char grid[N][N][N][N], gridd[N][N][N][N];

signed main() {
    freopen("input.txt", "r", stdin);
    rep(x, 0, N - 1) {
        rep(y, 0, N - 1) {
            rep(z, 0, N - 1) {
                rep(w, 0, N - 1) {
                    grid[x][y][z][w] = '.';
                }
            }
        }
    }
    int i = 0;
    string s;
    while(cin >> s) {
        i++;
        int j = 0;
        rall(c, s) {
            j++;
            grid[ORIG + i][ORIG + j][ORIG][ORIG] = c;
        }
    }
    rep(o, 1, 6) {
        rep(x, 1, N - 2) {
            rep(y, 1, N - 2) {
                rep(z, 1, N - 2) {
                    rep(w, 1, N - 2) {
                        char c = grid[x][y][z][w];
                        char& nc = gridd[x][y][z][w];
                        int cnt = 0;
                        rep(dx, -1, 1) {
                            rep(dy, -1, 1) {
                                rep(dz, -1, 1) {
                                    rep(dw, -1, 1) {
                                        if(dx == 0 && dy == 0 && dz == 0 && dw == 0) continue;
                                        cnt += grid[x + dx][y + dy][z + dz][w + dw] == '#';
                                    }
                                }
                            }
                        }
                        nc = c;
                        if(c == '#' && (cnt < 2 || cnt > 3)) {
                            nc = '.';
                        } else if(c == '.' && cnt == 3) {
                            nc = '#';
                        }
                    }
                }
            }
        }
        rep(x, 1, N - 2) {
            rep(y, 1, N - 2) {
                rep(z, 1, N - 2) {
                    rep(w, 1, N - 2) {
                        grid[x][y][z][w] = gridd[x][y][z][w];
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(x, 1, N - 2) {
        rep(y, 1, N - 2) {
            rep(z, 1, N - 2) {
                rep(w, 1, N - 2) {
                    ans += grid[x][y][z][w] == '#';
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
