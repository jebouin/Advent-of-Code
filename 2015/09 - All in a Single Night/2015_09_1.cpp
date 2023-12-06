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

const int M = 33;
string from[M], to[M];
int dist[M];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    set<string> st;
    string w;
    while(cin >> w) {
        from[++m] = w;
        cin >> w >> to[m] >> w >> dist[m];
        st.insert(from[m]);
        st.insert(to[m]);
    }
    vector<string> cities(rng(st));
    n = sz(cities);
    vector<int> ord(n);
    iota(rng(ord), 0);
    int ans = 1'000'000'000;
    do {
        int sum = 0;
        rep(i, 0, n - 2) {
            string u = cities[ord[i]], v = cities[ord[i + 1]];
            rep(j, 1, m) {
                if((from[j] == u && to[j] == v) || (from[j] == v && to[j] == u)) {
                    sum += dist[j];
                    break;
                }
            }
        }
        ans = min(ans, sum);
    } while(next_permutation(rng(ord)));
    cout << ans << endl;
    return 0;
}
