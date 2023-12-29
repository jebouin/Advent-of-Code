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

const int N = 1'111;
int x[N], y[N], z[N], vx[N], vy[N], vz[N];
int n;
int mini = 200'000'000'000'000, maxi = 400'000'000'000'000;

bool test(double x1, double y1, double u1, double v1, double x2, double y2, double u2, double v2) {
    double de = u1 * v2 - u2 * v1;
    if(de == 0) return false;
    double dx = x2 - x1, dy = y2 - y1;
    double de1 = v2 * dx - u2 * dy;
    double de2 = v1 * dx - u1 * dy;
    double t1 = de1 / de, t2 = de2 / de;
    if(t1 < 0 || t2 < 0) return false;
    double xi = x1 + t1 * u1;
    double yi = y1 + t1 * v1;
    return mini <= xi && xi <= maxi && mini <= yi && yi <= maxi;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        n++;
        x[n] = atoll(s.substr(0, sz(s) - 1).c_str());
        cin >> s;
        y[n] = atoll(s.substr(0, sz(s) - 1).c_str());
        cin >> s;
        z[n] = atoll(s.c_str());
        cin >> s >> s;
        vx[n] = atoll(s.substr(0, sz(s) - 1).c_str());
        cin >> s;
        vy[n] = atoll(s.substr(0, sz(s) - 1).c_str());
        cin >> s;
        vz[n] = atoll(s.c_str());
    }
    signed ans = 0;
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            ans += test(x[i], y[i], vx[i], vy[i], x[j], y[j], vx[j], vy[j]);
        }
    }
    cout << ans << endl;
    return 0;
}
