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

const int N = 111;
string grid[N];
int n;

void spin(int di, int dj) {
    while(1) {
        bool ch = false;
        rep(i, 1, n) {
            rep(j, 1, n) {
                if(grid[i][j] != 'O') continue;
                if(grid[i + di][j + dj] == '.') {
                    grid[i + di][j + dj] = 'O';
                    grid[i][j] = '.';
                    ch = true;
                }
            }
        }
        if(!ch) break;
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[++n] = "#" + s + "#";
    }
    vector<int> v(1, 0);
    map<int, int> mp;
    rep(i, 1, 1'000) {
        spin(-1, 0);
        spin(0, -1);
        spin(1, 0);
        spin(0, 1);
        int ans = 0;
        rep(i, 1, n) {
            int mult = n - i + 1;
            int add = 0;
            rep(j, 1, n) {
                add += grid[i][j] == 'O';
            }
            ans += add * mult;
        }
        v.pb(ans);
        if(i > 900) {
            int j = sz(v) - 2;
            while(v[j] != v.back()) {
                j--;
            }
            int len = sz(v) - j - 1;
            mp[len]++;
        }
    }
    int maxi = 0, len = 1;
    rall(p, mp) {
        if(p.se > maxi) {
            maxi = p.se;
            len = p.fi;
        }
    }
    int rem = 1'000'000'000;
    while(rem >= 1'000) {
        rem -= len;
    }
    cout << v[rem] << endl;
    return 0;
}
