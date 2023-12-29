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

const int N = 3'333;
map<string, int> mp;
int n;

int getn(string name) {
    if(mp.find(name) == mp.end()) {
        mp[name] = ++n;
    }
    return mp[name];
}

bool vis[N];
int flow[N][N], cap[N][N], par[N], dlev[N];
int augment(int nn, int u, int t, int limit) {
    if(limit <= 0) return 0;
    if(u == t) return limit;
    int ans = 0;
    rep(v, 1, nn) {
        int res = cap[u][v] - flow[u][v];
        if(dlev[v] == dlev[u] + 1 && res > 0) {
            int add = augment(nn, v, t, min(res, limit));
            flow[u][v] += add;
            flow[v][u] -= add;
            ans += add;
            limit -= add;
        }
    }
    if(!ans) dlev[u] = -1;
    return ans;
}
int dinic(int nn, int s, int t) {
    int ans = 0;
    queue<int> q;
    rep(i, 1, nn) {
        fill(flow[i] + 1, flow[i] + nn + 1, 0);
    }
    while(42) {
        q.push(s);
        fill(dlev + 1, dlev + nn + 1, -1);
        dlev[s] = 0;
        while(sz(q)) {
            int u = q.front();
            q.pop();
            rep(v, 1, nn) {
                if(dlev[v] == -1 && flow[u][v] < cap[u][v]) {
                    dlev[v] = dlev[u] + 1;
                    q.push(v);
                }
            }
        }
        if(dlev[t] == -1) {
            return ans;
        }
        int limit = 0;
        rep(u, 1, nn) {
            limit += cap[s][u];
        }
        limit -= ans;
        ans += augment(nn, s, t, limit);
    }
    return ans;
}

int dfs(int u) {
    if(vis[u]) return 0;
    vis[u] = true;
    int ans = 1;
    rep(v, 1, n) {
        if(cap[u][v] - flow[u][v] > 0) {
            ans += dfs(v);
        }
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line, s, t;
    while(getline(cin, line)) {
        stringstream ss(line);
        ss >> s;
        s.pop_back();
        int u = getn(s);
        while(ss >> t) {
            int v = getn(t);
            cap[u][v] = 1;
            cap[v][u] = 1;
        }
    }
    while(1) {
        int s = rand() % n + 1;
        int t = rand() % n + 1;
        if(s == t) continue;
        int f = dinic(n, s, t);
        if(f > 3) continue;
        fill(vis + 1, vis + n + 1, false);
        int cnt = dfs(s);
        int ans = cnt * (n - cnt);
        cout << ans << endl;
        break;
    }
    return 0;
}
