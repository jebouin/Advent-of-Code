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

const int N = 22;
map<string, int> nameToNode;
set<string> st;
int dist[N][N];
int n;

signed main() {
    freopen("input.txt", "r", stdin);
    string s, t, sign, _;
    int u, v, x;
    while(cin >> s) {
        cin >> _ >> sign >> x >> _ >> _ >> _ >> _ >> _ >> _ >> t;
        t.pop_back();
        if(st.find(s) == st.end()) {
            st.insert(s);
            nameToNode[s] = sz(st);
        }
        if(st.find(t) == st.end()) {
            st.insert(t);
            nameToNode[t] = sz(st);
        }
        u = nameToNode[s];
        v = nameToNode[t];
        dist[u][v] = sign == "lose" ? -x : x;
    }
    n = sz(st) + 1;
    vector<int> perm(n);
    iota(rng(perm), 1);
    int ans = 0;
    do {
        int cur = 0;
        rep(i, 0, n - 1) {
            int u = perm[i], v = perm[(i + 1) % n];
            cur += dist[u][v] + dist[v][u];
        }
        ans = max(ans, cur);
    } while(next_permutation(rng(perm)));
    cout << ans << endl;
    return 0;
}

