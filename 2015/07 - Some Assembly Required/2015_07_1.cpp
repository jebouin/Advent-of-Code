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

struct Transition {
    string par1, par2, res, op, line;

    Transition(string line) {
        this->line = line;
        stringstream ss(line);
        string w;
        vector<string> v;
        while(ss >> w) {
            v.pb(w);
        }
        if(sz(v) == 3) {
            par1 = v[0];
            op = "SET";
            res = v[2];
        } else if(sz(v) == 4) {
            op = v[0];
            par1 = v[1];
            res = v[3];
        } else if(sz(v) == 5) {
            par1 = v[0];
            op = v[1];
            par2 = v[2];
            res = v[4];
        }
    }
};

vector<Transition> all;
map<string, int> mem;

int solve(string s) {
    if(mem.find(s) != mem.end()) {
        return mem[s];
    }
    bool found = false;
    int ans;
    rall(tr, all) {
        if(tr.res == s) {
            found = true;
            int x = solve(tr.par1);
            int y = solve(tr.par2);
            if(tr.op == "SET") {
                ans = x;
            } else if(tr.op == "NOT") {
                ans = ~x;
            } else if(tr.op == "AND") {
                ans = x & y;
            } else if(tr.op == "OR") {
                ans = x | y;
            } else if(tr.op == "LSHIFT") {
                ans = x << y;
            } else if(tr.op == "RSHIFT") {
                ans = x >> y;
            } else {
                cout << "Invalid operation " << tr.op << endl;
                exit(1);
            }
        }
    }
    if(!found) {
        ans = atoi(s.c_str());
    }
    mem[s] = ans;
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        Transition tr(line);
        all.pb(tr);
    }
    int ans = solve("a");
    cout << ans << endl;
    return 0;
}
