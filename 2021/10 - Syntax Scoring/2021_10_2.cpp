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

string op = "([{<", cl = ")]}>";
vector<int> pts = {1, 2, 3, 4};

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    vector<int> v;
    while(cin >> s) {
        string st;
        bool ok = true;
        rall(c, s) {
            if(op.find(c) != string::npos) {
                st += c;
            } else {
                int id = cl.find(c);
                if(st.empty() || st.back() != op[id]) {
                    ok = false;
                    break;
                }
                st.pop_back();
            }
        }
        if(!ok) continue;
        int val = 0;
        while(sz(st)) {
            char c = st.back();
            st.pop_back();
            val = 5 * val + pts[op.find(c)];
        }
        v.pb(val);
    }
    sort(rng(v));
    int ans = v[sz(v) / 2];
    cout << ans << endl;
    return 0;
}
