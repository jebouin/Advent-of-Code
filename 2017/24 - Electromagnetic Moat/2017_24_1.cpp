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

const int N = 111, X = 111;
int a[N], b[N];
int n;

int solve(set<int>& st, int last = 0) {
    int ans = 0;
    vector<int> v(rng(st));
    rall(i, v) {
        st.erase(i);
        int add = a[i] + b[i];
        if(last == a[i]) {
            int cur = solve(st, b[i]) + add;
            ans = max(ans, cur);
        } else if(last == b[i]) {
            int cur = solve(st, a[i]) + add;
            ans = max(ans, cur);
        }
        st.insert(i);
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        n++;
        int pos = s.find("/");
        a[n] = atoi(s.substr(0, pos).c_str());
        b[n] = atoi(s.substr(pos + 1).c_str());
    }
    vector<int> v(n);
    iota(rng(v), 1);
    set<int> st(rng(v));
    int ans = solve(st);
    cout << ans << endl;
    return 0;
}
