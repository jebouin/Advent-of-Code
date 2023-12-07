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

inline bool isp(char c, char cc) {
    return c != cc && toupper(c) == toupper(cc);
}

int react(string s) {
    string st;
    rall(c, s) {
        st += c;
        while(st.size() >= 2 && isp(st[st.size() - 1], st[st.size() - 2])) {
            st.erase(st.begin() + st.size() - 1);
            st.erase(st.begin() + st.size() - 1);
        }
    }
    return st.size();
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int mini = 1'000'000;
    rep(i, 0, 25) {
        string ss;
        rall(c, s) {
            if(c != 'a' + i && c != 'A' + i) {
                ss += c;
            }
        }
        int cur = react(ss);
        if(cur < mini) {
            mini = cur;
        }
    }
    cout << mini << endl;
    return 0;
}
