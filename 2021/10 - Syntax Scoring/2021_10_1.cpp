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
vector<int> pts = {3, 57, 1197, 25137};

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    int ans = 0;    
    while(cin >> s) {
        string st;
        rall(c, s) {
            if(op.find(c) != string::npos) {
                st += c;
            } else {
                int id = cl.find(c);
                if(st.empty() || st.back() != op[id]) {
                    ans += pts[id];
                    break;
                }
                st.pop_back();
            }
        }
    }
    cout << ans << endl;
    return 0;
}
