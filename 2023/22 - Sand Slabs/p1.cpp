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

struct Brick {
    int xMin, yMin, zMin, xMax, yMax, zMax;

    void read(string s) {
        int c1 = s.find(',');
        int c2 = s.find(',', c1 + 1);
        int t = s.find('~', c2 + 1);
        int c3 = s.find(',', t + 1);
        int c4 = s.find(',', c3 + 1);
        xMin = atoi(s.substr(0, c1).c_str());
        yMin = atoi(s.substr(c1 + 1, c2 - c1 + 1).c_str());
        zMin = atoi(s.substr(c2 + 1, t - c2 + 1).c_str());
        xMax = atoi(s.substr(t + 1, c3 - t + 1).c_str());
        yMax = atoi(s.substr(c3 + 1, c4 - c3 + 1).c_str());
        zMax = atoi(s.substr(c4 + 1).c_str());
    }
};

const int N = 11'111;
Brick all[N], cop[N];
vector<int> bel[N];
int n;

int step(bool r, int ign = -1) {
    int ans = 0;
    rep(i, 1, n) {
        if(i == ign) continue;
        Brick& top = all[i];
        if(top.zMin == 0) continue;
        bool ok = true;
        rep(j, 1, n) {
            if(i == j || j == ign) continue;
            Brick& bot = all[j];
            if(top.xMin > bot.xMax || top.xMax < bot.xMin) continue;
            if(top.yMin > bot.yMax || top.yMax < bot.yMin) continue;
            if(top.zMin - 1 > bot.zMax || top.zMax - 1 < bot.zMin) continue;
            ok = false;
            break;
        }
        if(ok) {
            if(r) {
                top.zMin--;
                top.zMax--;
            }
            ans++;
        }
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        n++;
        all[n].read(line);
    }
    while(1) {
        int ch = step(true);
        if(!ch) break;
    }
    int ans = 0;
    rep(i, 1, n) {
        Brick& b = all[i];
        b.zMin -= 1'000'000;
        b.zMin -= 1'000'000;
        ans += step(false, i);
        b.zMin += 1'000'000;
        b.zMin += 1'000'000;
    }
    cout << ans << endl;
    return 0;
}
