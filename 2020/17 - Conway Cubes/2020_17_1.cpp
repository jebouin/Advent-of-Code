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

const int N = 10;

map<vector<int>, char> getEmpty() {
    map<vector<int>, char> mp;    
    rep(x, -N, 2 * N) {
        rep(y, -N, 2 * N) {
            rep(z, -N, 2 * N) {
                mp[{x, y, z}] = '.';
            }
        }
    }
    return mp;
}

signed main() {
    freopen("input.txt", "r", stdin);
    auto mp = getEmpty();
    int i = 0;
    string s;
    while(cin >> s) {
        i++;
        int j = 0;
        rall(c, s) {
            j++;
            mp[{i, j, 0}] = c;
        }
    }
    rep(o, 1, 6) {
        map<vector<int>, char> mpp = getEmpty();
        rall(p, mp) {
            int x = p.fi[0], y = p.fi[1], z = p.fi[2];
            int cnt = 0;
            rep(dx, -1, 1) {
                rep(dy, -1, 1) {
                    rep(dz, -1, 1) {
                        if(dx == 0 && dy == 0 && dz == 0) continue;
                        vector<int> pos = {x + dx, y + dy, z + dz};
                        if(mp.find(pos) == mp.end()) continue;
                        cnt += mp[pos] == '#';
                    }
                }
            }
            mpp[p.fi] = p.se;
            if(p.se == '#' && (cnt < 2 || cnt > 3)) {
                mpp[p.fi] = '.';
            } else if(p.se == '.' && cnt == 3) {
                mpp[p.fi] = '#';
            }
        }
        mp = mpp;
    }
    int ans = 0;
    rall(p, mp) {
        ans += p.se == '#';
    }
    cout << ans << endl;
    return 0;
}
