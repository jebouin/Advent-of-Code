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

const int INF = 1'000'000'000'000'000'000;
const int N = 22, K = 111, D = 111;
int from[N][K], to[N][K], len[N][K];
int seeds[D], ml[N];
int n, d;

int dfs(int i, int l, int r) {
    if(i > n) return l;
    int ans = INF;
    vector<pair<int, int> > mapped;
    rep(j, 1, ml[i]) {
        int ml = from[i][j], mr = from[i][j] + len[i][j] - 1;
        int add = to[i][j] - from[i][j];
        ml = max(ml, l);
        mr = min(mr, r);
        if(ml > mr) continue;
        mapped.pb({ml, mr});
        int cur = dfs(i + 1, ml + add, mr + add);
        ans = min(ans, cur);
    }
    sort(rng(mapped));
    int curl = l;
    rall(p, mapped) {
        int ml = curl, mr = p.fi - 1;
        if(ml <= mr) {
            int cur = dfs(i + 1, ml, mr);
            ans = min(ans, cur);
        }
        curl = p.se + 1;
    }
    int ml = curl, mr = r;
    if(ml <= mr) {
        int cur = dfs(i + 1, ml, mr);
        ans = min(ans, cur);
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string w, line;
    getline(cin, line);
    stringstream ss(line);
    ss >> w;
    int x;
    while(ss >> x) {
        seeds[++d] = x;
    }
    getline(cin, line);
    while(getline(cin, line)) {
        n++;
        while(getline(cin, line)) {
            if(line == "") break;
            stringstream ss(line);
            ml[n]++;
            ss >> to[n][ml[n]] >> from[n][ml[n]] >> len[n][ml[n]];
        }
    }
    int ans = INF;
    rep(dd, 1, d / 2) {
        int l = seeds[dd * 2 - 1], cnt = seeds[dd * 2];
        int cur = dfs(1, l, l + cnt - 1);
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
