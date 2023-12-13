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

const int N = 2'222;
vector<int> graph[N];
int col[N];
int n;

int dfs(int u, int c) {
    if(col[u]) return 0;
    col[u] = c;
    int ans = 1;
    rall(v, graph[u]) {
        ans += dfs(v, c);
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        line += ",";
        stringstream ss(line);
        int u;
        ss >> u;
        u++;
        int v = 0;
        char c;
        while(ss >> c) {
            if(isdigit(c)) {
                v = 10 * v + c - '0';
            } else if(v) {
                v++;
                graph[u].pb(v);
                graph[v].pb(u);
                v = 0;
            }
        }
        ++n;
    }
    int ans = 0;
    rep(u, 1, n) {
        if(col[u]) continue;
        dfs(u, ++ans);
    }
    cout << ans << endl;
    return 0;
}

