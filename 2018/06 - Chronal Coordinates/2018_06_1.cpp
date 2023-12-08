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

const int K = 111;
int x[K], y[K];
int k;

vector<int> solve(int n) {
    vector<int> ans(k + 1);
    rep(i, -n, n) {
        rep(j, -n, n) {
            int mini = 1'000'000, best = -1;
            rep(l, 1, k) {
                int cd = abs(i - x[l]) + abs(j - y[l]);
                if(cd < mini) {
                    mini = cd;
                    best = l;
                }
            }
            ans[best]++;
        }
    }
    return ans; 
}

signed main() {
    freopen("input.txt", "r", stdin);
    char c;
    while(cin >> x[k + 1] >> c >> y[k + 1]) {
        k++;
    }
    // An area i is finite iff solve(n)_i == solve(n + 1)_i for n large enough
    vector<int> cnt = solve(400), cntt = solve(401);
    int maxi = 0;
    rep(i, 1, k) {
        if(cnt[i] == cntt[i] && cnt[i] > maxi) {
            maxi = cnt[i];
        }
    }
    cout << maxi << endl;
    return 0;
}
