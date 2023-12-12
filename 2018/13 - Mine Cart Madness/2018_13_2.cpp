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
#define rall(x,a) for(auto& x : a)
#define MOD 1000000007
#ifndef LOCAL
#define endl "\n"
#define cerr if(0) cerr
#endif

typedef long long ll;
using namespace std;

const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const string CART = "v>^<";
vector<string> grid;

struct Cart {
    int x, y, d, dd;
    bool dead;
    Cart(int x, int y, int d) : x(x), y(y), d(d), dd(1), dead(false) {}
    bool move(vector<Cart>& carts) {
        int nx = x + DX[d];
        int ny = y + DY[d];
        char c = grid[ny][nx];
        if(c == '\\') {
            d ^= 1;
        } else if(c == '/') {
            d = ((d + 2) ^ 1) % 4;
        } else if(c == '+') {
            d = (d + dd + 4) % 4;
            dd--;
            if(dd < -1) dd = 1;
        }
        x = nx;
        y = ny;
        rall(c, carts) {
            if(c.x == x && c.y == y && !(c.d == d && c.dd == dd)) {
                c.dead = true;
                dead = true;
                return false;
            }
        }
        return true;
    }
};
vector<Cart> carts;

bool comp(const Cart& x, const Cart& y) {
    if(x.y < y.y) return true;
    if(x.y > y.y) return false;
    return x.x < y.x;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        grid.pb(line);
    }
    int n = sz(grid), m = sz(grid[0]);
    grid.pb(string(m + 2, ' '));
    grid.insert(grid.begin(), string(m + 2, ' '));
    rep(i, 1, n) {
        grid[i] = " " + grid[i] + " ";
        rep(j, 1, m) {
            char c = grid[i][j];
            int p = CART.find(c);
            if(p != (int)string::npos) {
                Cart cart(j, i, p);
                carts.pb(cart);
                if(p % 2) grid[i][j] = '-';
                else grid[i][j] = '|';
            }
        }
    }
    while(1) {
        sort(rng(carts), comp);
        vector<Cart> nc;
        rall(c, carts) {
            c.move(carts);
        }
        rall(c, carts) {
            if(!c.dead) {
                nc.pb(c);
            }
        }
        carts = nc;
        if(sz(carts) == 1) {
            cout << carts[0].x - 1 << "," << carts[0].y - 1 << endl;
            return 0;
        }
    }
    return 0;
}

