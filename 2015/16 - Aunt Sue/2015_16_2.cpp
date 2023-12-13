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
    string line, _, s;
    map<string, int> tape = {
        {"childen", 3},
        {"cats", 7},
        {"samoyeds", 2},
        {"pomeranians", 3},
        {"akitas", 0},
        {"vizslas", 0},
        {"goldfish", 5},
        {"trees", 3},
        {"cars", 2},
        {"perfumes", 1},
    };
    while(getline(cin, line)) {
        map<string, int> mp;
        stringstream ss(line);
        int id, x;
        char c;
        ss >> _ >> id >> _;
        while(ss >> s) {
            s.pop_back();
            ss >> x >> c;
            mp[s] = x;
        }
        bool ok = true;
        rall(p, mp) {
            int need = tape[p.fi], has = p.se;
            if((p.fi == "cats" || p.fi == "trees")) {
                if(has <= need) {
                    ok = false;
                }
            } else if((p.fi == "pomeranians" || p.fi == "goldfish")) {
                if(has >= need) {
                    ok = false;
                }
            } else if(tape[p.fi] != p.se) {
                ok = false;
            }
        }
        if(ok) {
            cout << id << endl;
            return 0;
        }
    }
    return 0;
}
