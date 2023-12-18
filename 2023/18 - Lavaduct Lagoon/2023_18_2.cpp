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

const string DIRS = "RDLU";
const int N = 1'000, A = 500;
int grid[N][N];
int ans = 0;

int det(int i1, int j1, int i2, int j2) {
    return i1 * j2 - j1 * i2;
}

signed main() {
    freopen("input.txt", "r", stdin);
    char dir;
    int dist;
    string s;
    vector<pair<int, int> > pts = {{0, 0}};
    int i = 0, j = 0;
    int ans = 0;
    while(cin >> dir) {
        cin >> dist >> s;
        s = s.substr(2, 6);
        dist = 0;
        rep(i, 0, 4) {
            int di = isdigit(s[i]) ? s[i] - '0' : 10 + s[i] - 'a';
            dist = dist * 16 + di;
        }
        dir = DIRS[s[5] - '0'];
        cout << dir << " " << dist << endl;
        if(dir == 'L') {
            j += dist;
            ans += dist;
        } else if(dir == 'R') {
            j -= dist;
            ans += dist;
        } else if(dir == 'U') {
            i -= dist;
            ans += dist;
        } else if(dir == 'D') {
            ans += dist;
            i += dist;
        }
        pts.pb({i, j});
    }
    // TODO: Why is this needed?
    ans += 2;
    int n = sz(pts);
    rep(i, 0, n - 1) {
        int ii = (i + 1) % n;
        int add = det(pts[i].fi, pts[i].se, pts[ii].fi, pts[ii].se);
        ans += add;
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}
