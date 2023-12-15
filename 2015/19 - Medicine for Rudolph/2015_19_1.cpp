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

const int N = 111;
string from[N], to[N];
int n, m;

signed main() {
    freopen("input.txt", "r", stdin);
    string line, s;
    while(getline(cin, line)) {
        if(line == "") break;
        string _;
        stringstream ss(line);
        m++;
        ss >> from[m] >> _ >> to[m];
    }
    cin >> s;
    n = sz(s);
    set<string> st;
    rep(i, 0, n - 1) {
        rep(j, 1, m) {
            string sub = s.substr(i, sz(from[j]));
            if(sub == from[j]) {
                string t = s.substr(0, i) + to[j] + s.substr(i + sz(from[j]));
                st.insert(t);
            }
        }
    }
    cout << sz(st) << endl;
    return 0;
}
