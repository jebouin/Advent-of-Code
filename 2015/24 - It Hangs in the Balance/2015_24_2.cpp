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

const int X = 3'333;
bool dp[X][X];

bool solve(vector<int> v, int sum) {
    int total = 0;
    rall(x, v) {
        total += x;
    }
    if(total != 3 * sum) return false;
    rep(x, 0, sum) {
        fill(dp[x], dp[x] + sum + 1, false);
    }
    dp[0][0] = true;
    rep(i, 0, sz(v) - 1) {
        rrep(x, 0, sum) {
            rrep(y, 0, sum) {
                if(x >= v[i]) {
                    dp[x][y] |= dp[x - v[i]][y];
                }
                if(y >= v[i]) {
                    dp[x][y] |= dp[x][y - v[i]];
                }
            }
        }
    }
    return dp[sum][sum];
}

signed main() {
    freopen("input.txt", "r", stdin);
    vector<int> v;
    int x;
    while(cin >> x) {
        v.pb(x);
    }
    int n = sz(v), cnt = 0;
    int ans = 1'000'000'000'000'000'000;
    bool found = false;
    while(!found) {
        cnt++;
        rep(mask, 0, (1 << n) - 1) {
            if(pcnt(mask) != cnt) continue;
            int ent = 1, sum = 0;
            vector<int> rem;
            rep(i, 0, n - 1) {
                if(mask & (1 << i)) {
                    ent *= v[i];
                    sum += v[i];
                } else {
                    rem.pb(v[i]);
                }
            }
            if(solve(rem, sum)) {
                ans = min(ans, ent);
                found = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
