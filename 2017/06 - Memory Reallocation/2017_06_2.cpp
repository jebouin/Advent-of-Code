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

int solve(vector<int>& state) {
    set<vector<int> > st;
    int ans = 0;
    while(st.find(state) == st.end()) {
        st.insert(state);
        ans++;
        int bi = 0, maxi = -1;
        rep(i, 0, sz(state) - 1) {
            if(state[i] > maxi) {
                maxi = state[i];
                bi = i;
            }
        }
        state[bi] = 0;
        while(maxi) {
            bi = (bi + 1) % sz(state);
            maxi--;
            state[bi]++;
        }
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    vector<int> state;
    int x;
    while(cin >> x) {
        state.pb(x);
    }
    solve(state);
    int ans = solve(state);
    cout << ans << endl;
    return 0;
}
