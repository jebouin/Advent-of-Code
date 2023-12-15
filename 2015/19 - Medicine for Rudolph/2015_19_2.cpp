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

const int INF = 1'000'000;
const int N = 111;
string from[N], to[N];
int m;
set<string> st;
string goal;

int solve(string s, int maxLen, int cnt=0) {
    if(s == goal) {
        return cnt;
    }
    if(st.find(s) != st.end() || (sz(s) >= sz(goal) && s != goal)) {
        return INF;
    }
    if(sz(s) > maxLen && s.substr(0, sz(s) - maxLen) != goal.substr(0, sz(s) - maxLen)) {
        return INF;
    }
    st.insert(s);
    rep(i, 0, sz(s) - 1) {
        rep(j, 1, m) {
            string sub = s.substr(i, sz(from[j]));
            if(sub == from[j]) {
                string t = s.substr(0, i) + to[j] + s.substr(i + sz(from[j]));
                int ans = solve(t, maxLen, cnt + 1);
                if(ans < INF) {
                    return ans;
                }
            }
        }
    }
    return INF;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        if(line == "") break;
        string _;
        stringstream ss(line);
        m++;
        ss >> from[m] >> _ >> to[m];
    }
    cin >> goal;
    rep(len, 1, 20) {
        st.clear();
        int ans = solve("e", len);
        if(ans != INF) {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}
