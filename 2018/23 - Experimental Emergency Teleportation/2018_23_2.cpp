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

int f(int px, int py, int pz) {
    int ans = 0;
    rep(i, 1, n) {
        int dx = x[i] - px;
        int dy = y[i] - py;
        int dz = z[i] - pz;
        int dist = abs(dx) + abs(dy) + abs(dz);
        ans += dist <= r[i];
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
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
    }
    int cx = 0, cy = 0, cz = 0, d = 100'000'000;
    int maxi, bx = 0, by = 0, bz = 0, bd = 0;
    while(d) {
        maxi = -1;
        int m = 10 * d;
        for(int i = cx - m; i <= cx + m; i += d) {
            for(int j = cy - m; j <= cy + m; j += d) {
                for(int k = cz - m; k <= cz + m; k += d) {
                    int cnt = f(i, j, k);
                    if(cnt > maxi) {
                        maxi = cnt;
                        bx = i, by = j, bz = k;
                        bd = abs(i) + abs(j) + abs(k);
                    } else if(cnt == maxi && abs(i) + abs(j) + abs(k) < bd) {
                        bx = i, by = j, bz = k;
                        bd = abs(i) + abs(j) + abs(k);
                    }
                }
            }
        }
        cx = bx, cy = by, cz = bz;
        d /= 10;
    }
    int ans = abs(bx) + abs(by) + abs(bz);
    cout << ans << endl;
    return 0;
}

