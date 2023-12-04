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

const int N = 222;
int a[N], p[N], b[N];
int n = 207;

signed main() {
    freopen("input.txt", "r", stdin);
    int ans = 0;
    rep(i, 1, n) {
        string line, w;
        getline(cin, line);
        stringstream ss(line);
        ss >> w >> w;
        set<int> st;
        rep(j, 1, 10) {
            int x;
            ss >> x;
            st.insert(x);
        }
        ss >> w;
        int cnt = 0, x;
        while(ss >> x) {
            cnt += st.find(x) != st.end();
        }
        if(cnt > 0) {
            ans += 1 << (cnt - 1);
        }
    }
    cout << ans << endl;
    return 0;
}
