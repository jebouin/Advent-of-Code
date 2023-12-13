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

const int INF = 1'000'000'000;
const int N = 1'111;
int x[N], y[N], z[N], r[N];
int n;

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    int br = -1, bi = 1;
    while(getline(cin, line)) {
        n++;
        vector<int> v;
        int num = 0;
        bool neg = false, has = false;
        rall(c, line) {
            if(isdigit(c)) {
                num = 10 * num + c - '0';
                has = true;
            } else if(c == '-') {
                neg = true;
            } else if(has) {
                v.pb(neg ? -num : num);
                num = 0;
                neg = false;
                has = false;
            }
        }
        v.pb(neg ? -num : num);
        x[n] = v[0];
        y[n] = v[1];
        z[n] = v[2];
        r[n] = v[3];
        if(r[n] > br) {
            br = r[n];
            bi = n;
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        int dx = x[i] - x[bi];
        int dy = y[i] - y[bi];
        int dz = z[i] - z[bi];
        int dist = abs(dx) + abs(dy) + abs(dz);
        ans += dist <= br;
    }
    cout << ans << endl;
    return 0;
}

