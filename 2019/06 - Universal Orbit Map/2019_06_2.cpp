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

typedef long long ll;
using namespace std;

const int N = 111111;
vector<int> graph[N];
int in[N], par[N], depth[N];
int n;

void dfs(int u, int p = 0) {
    if(p) {
        depth[u] = depth[p] + 1;
    }
    par[u] = p;
    rall(v, graph[u]) {
        dfs(v, u);
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    map<string, int> mp;
    set<string> st;
    string line;
    while(cin >> line) {
        string us = line.substr(0, 3);
        string vs = line.substr(4, 3);
        if(st.find(us) == st.end()) {
            st.insert(us);
            mp[us] = ++n;
        }
        if(st.find(vs) == st.end()) {
            st.insert(vs);
            mp[vs] = ++n;
        }
        int u = mp[us];
        int v = mp[vs];
        graph[u].pb(v);
        in[v]++;
    }
    int root = 1;
    rep(i, 1, n) {
        if(!in[i]) {
            root = i;
        }
    }
    dfs(root);
    int you = mp["YOU"], san = mp["SAN"];
    int d1 = depth[you], d2 = depth[san];
    while(you != san) {
        if(depth[you] > depth[san]) {
            you = par[you];
        } else {
            san = par[san];
        }
    }
    int anss = d1 + d2 - 2 * depth[san] - 2;
    cout << anss << endl;    
    return 0;
}
