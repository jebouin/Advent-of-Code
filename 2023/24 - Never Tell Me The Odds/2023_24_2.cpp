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
double x[N], y[N], z[N], u[N], v[N], w[N];
int n;

double det(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    return a * e * i - a * f * h - b * d * i + b * f * g + c * d * h - c * e * g;
}

bool intersect(double x1, double y1, double z1, double u1, double v1, double w1, double x2, double y2, double z2, double u2, double v2, double w2) {
    double tx = (x1 - x2) / (u2 - u1);
    double ty = (y1 - y2) / (v2 - v1);
    double tz = (z1 - z2) / (w2 - w1);
    return abs(tx - ty) < .01 && abs(tx - tz) < .01 && tx > 0;
}

bool test(double ur, double vr, double wr, double xr, double yr, double zr) {
    rep(i, 1, 1) {
        if(!intersect(xr, yr, zr, ur, vr, wr, x[i], y[i], z[i], u[i], v[i], w[i])) {
            return false;
        }
    }
    return true;
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
        u[n] = atoll(s.substr(0, sz(s) - 1).c_str());
        cin >> s;
        v[n] = atoll(s.substr(0, sz(s) - 1).c_str());
        cin >> s;
        w[n] = atoll(s.c_str());
    }
    int k = 500;
    rep(ur, -k, k) {
        rep(vr, -k, k) {
            rep(wr, -k, k) {
                double cxy = y[1] * (ur - u[1]) + x[1] * (v[1] - vr) + y[2] * (u[2] - ur) + x[2] * (vr - v[2]);
                double cxz = z[2] * (ur - u[2]) + x[2] * (w[2] - wr) + z[3] * (u[3] - ur) + x[3] * (wr - w[3]);
                double cyz = z[3] * (vr - v[3]) + y[3] * (w[3] - wr) + z[4] * (v[4] - vr) + y[4] * (wr - w[4]);
                double a = v[1] - v[2], b = u[2] - u[1], c = 0;
                double d = w[2] - w[3], e = 0, f = u[3] - u[2];
                double g = 0, h = w[3] - w[4], i = v[4] - v[3];
                double de = det(a, b, c, d, e, f, g, h, i);
                if(de == 0) continue;
                double xr = det(cxy, b, c, cxz, e, f, cyz, h, i) / de;
                double yr = det(a, cxy, c, d, cxz, f, g, cyz, i) / de;
                double zr = det(a, b, cxy, d, e, cxz, g, h, cyz) / de;
                if(test(ur, vr, wr, xr, yr, zr)) {
                    int ans = round(xr) + round(yr) + round(zr);
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
