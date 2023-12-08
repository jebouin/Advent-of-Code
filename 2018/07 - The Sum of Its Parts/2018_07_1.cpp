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

const int N = 33;
vector<int> graph[N];
int indeg[N];
int n;

signed main() {
    freopen("input.txt", "r", stdin);
    n = 26;
    string line;
    vector<string> lines;
    while(getline(cin, line)) {
        lines.pb(line);
    }
    sort(rng(lines));
    rall(line, lines) {
        int from = 0, to = 0;
        rep(i, 1, sz(line) - 1) {
            char c = line[i];
            if(toupper(c) == c && isalpha(c)) {
                if(from) {
                    to = c - 'A' + 1;
                } else {
                    from = c - 'A' + 1;
                }
            }
        }
        graph[from].pb(to);
        indeg[to]++;
    }
    set<int> st;
    rep(u, 1, n) {
        if(indeg[u]) continue;
        st.insert(u);
    }
    string ans;
    while(sz(st)) {
        int u = *(st.begin());
        st.erase(u);
        rall(v, graph[u]) {
            indeg[v]--;
            if(!indeg[v]) {
                st.insert(v);
            }
        }
        ans += 'A' + u - 1;
    }
    cout << ans << endl;
    return 0;
}
