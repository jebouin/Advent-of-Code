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

signed main() {
    freopen("input.txt", "r", stdin);
    int gens = 20;
    string s;
    cin >> s >> s >> s;
    s = string(gens, '.') + s + string(gens, '.');
    string line;
    vector<pair<string, char> > rules;
    while(getline(cin, line)) {
        stringstream ss(line);
        string r, a, c;
        ss >> r >> a >> c;
        rules.pb(make_pair(r, c[0]));
    }
    vector<int> sums;
    rep(g, 1, gens) {
        string t(sz(s), '.');
        rep(i, 0, sz(s) - 1) {
            rall(p, rules) {
                bool match = true;
                rep(j, 0, 4) {
                    int ii = i + j - 2;
                    char c = ii < 0 ? '.' : (ii >= sz(s) ? '.' : s[ii]);
                    if(p.first[j] != c) {
                        match = false;
                        break;
                    }
                }
                if(match) {
                    t[i] = p.second;
                    break;
                }
            }
        }
        s = t;
        int ans = 0;
        rep(i, 0, sz(s) - 1) {
            if(s[i] == '#') {
                ans += i - gens;
            }
        }
        sums.pb(ans);
    }
    cout << sums.back() << endl;
    return 0;
}
