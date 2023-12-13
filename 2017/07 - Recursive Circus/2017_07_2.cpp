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
set<string> names;
map<string, int> nameToNode;
vector<int> tree[N];
int weight[N], in[N], total[N];
string all[N];
int n;

void addNode(string name) {
    if(names.find(name) == names.end()) {
        names.insert(name);
        n++;
        nameToNode[name] = n;
        all[n] = name;
    }
}
int getNode(string name) {
    if(nameToNode.find(name) == nameToNode.end()) {
        addNode(name);
    }
    return nameToNode[name];
}

void dfs(int u) {
    total[u] = weight[u];
    rall(v, tree[u]) {
        dfs(v);
        total[u] += total[v];
    }
}

void dfs2(int u) {
    map<int, int> mp;
    rall(v, tree[u]) {
        dfs2(v);
        mp[total[v]]++;
    }
    if(sz(mp) == 1) {
        return;
    }
    int from = 0, to = 0;
    rall(p, mp) {
        if(p.se == 1) {
            from = p.fi;
        } else {
            to = p.fi;
        }
    }
    rall(v, tree[u]) {
        if(total[v] == from) {
            cout << weight[v] - from + to << endl;
            exit(0);
        }
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line, s;
    char _;
    while(getline(cin, line)) {
        stringstream ss(line);
        int x;
        ss >> s >> _ >> x >> _;
        int u = getNode(s);
        weight[u] = x;
        if(ss >> s) {
            while(ss >> s) {
                if(s.back() == ',') {
                    s.pop_back();
                }
                int v = getNode(s);
                tree[u].pb(v);
                in[v]++;
            }
        }
    }
    int root = 1;
    rep(u, 1, n) {
        if(in[u] == 0) {
            root = u;
        }
    }
    dfs(root);
    dfs2(root);
    return 0;
}

