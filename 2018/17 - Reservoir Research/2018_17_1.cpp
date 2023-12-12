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

int readInt() {
    char c;
    bool start = false, neg = false;
    int ans = 0;
	while(true) {
		c = getchar();
        if((c < '0' || c > '9') && c != '-') {
            if(start) break;
            else continue;
        }
        ans *= 10;
		start = true;
		if(c == '-') neg = true;
		else ans += c - '0';
	}
    return neg ? -ans : ans;
}

const int INF = 1'000'000'000;
const int N = 2'222;
string grid[N];
int minx = INF, maxx = -INF, miny = INF, maxy = -INF;

bool flow(int i, int j) {
    if(i >= N - 2 || i < 0 || j < 2 || j >= N - 2) {
        return false;
    }
    grid[i][j] = 'o';
    bool ok = true;
    if(grid[i + 1][j] == ' ') {
        ok &= flow(i + 1, j);
    } else if(grid[i + 1][j] == 'o') {
        ok = false;
    }
    if(ok) {
        if(grid[i][j - 1] == ' ') {
            ok &= flow(i, j - 1);
        }
        if(grid[i][j + 1] == ' ') {
            ok &= flow(i, j + 1);
        }
    }
    if(ok) {
        grid[i][j] = 'O';
    } else {
        int k = j + 1;
        while(grid[i][k] == 'O') {
            grid[i][k] = 'o';
            k++;
        }
        k = j - 1;
        while(grid[i][k] == 'O') {
            grid[i][k] = 'o';
            k--;
        }
    }
    return ok;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    rep(i, 0, N - 1) {
        grid[i] = string(N, ' ');
    }
    while(1) {
        char c = getchar();
        if(c == EOF) break;
        if(c == 'x') {
            int x = readInt(), y1 = readInt(), y2 = readInt();
            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y1);
            maxy = max(maxy, y2);
            rep(y, y1, y2) {
                grid[y][x] = '#';
            }
        } else {
            int y = readInt(), x1 = readInt(), x2 = readInt();
            minx = min(minx, x1);
            maxx = max(maxx, x2);
            miny = min(miny, y);
            maxy = max(maxy, y);
            rep(x, x1, x2) {
                grid[y][x] = '#';
            }
        }
    }
    flow(0, 500);
    int ans = 0;
    rep(i, miny, maxy) {
        rep(j, 0, N - 1) {
            ans += grid[i][j] == 'O' || grid[i][j] == 'o';
        }
    }
    cout << ans << endl;
    return 0;
}

