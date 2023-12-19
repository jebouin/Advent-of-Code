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

const int INF = 1'000'000'000;

struct Part {
    int xMin = 1, xMax = 4000;
    int mMin = 1, mMax = 4000;
    int aMin = 1, aMax = 4000;
    int sMin = 1, sMax = 4000;

    int count() {
        int ans = 1;
        ans *= max(0ll, (xMax - xMin + 1));
        ans *= max(0ll, (mMax - mMin + 1));
        ans *= max(0ll, (aMax - aMin + 1));
        ans *= max(0ll, (sMax - sMin + 1));
        return ans;
    }
};

struct Rule {
    string var, op, val, to;
    bool def = false;

    void parse(string s) {
        int sm = s.find("<"), gr = s.find(">"), col = s.find(":");
        int comp = sm == string::npos ? gr : sm;
        if(comp == string::npos) {
            to = s;
            def = true;
            return;
        }
        var = s.substr(0, comp);
        op = s.substr(comp, 1);
        val = s.substr(comp + 1, col - comp - 1);
        to = s.substr(col + 1);
    }

    Part apply(Part p, bool inv) {
        if(def) {
            return p;
        }
        string op = this->op;
        int mult = 1;
        if(inv) {
            op = op == "<" ? ">" : "<";
            mult = 0;
        }
        int x = 0, y = atoi(val.c_str());
        if(var == "x") {
            if(op == "<") {
                p.xMax = min(p.xMax, y - mult);
            } else {
                p.xMin = max(p.xMin, y + mult);
            }
        }
        if(var == "m") {
            if(op == "<") {
                p.mMax = min(p.mMax, y - mult);
            } else {
                p.mMin = max(p.mMin, y + mult);
            }
        }
        if(var == "a") {
            if(op == "<") {
                p.aMax = min(p.aMax, y - mult);
            } else {
                p.aMin = max(p.aMin, y + mult);
            }
        }
        if(var == "s") {
            if(op == "<") {
                p.sMax = min(p.sMax, y - mult);
            } else {
                p.sMin = max(p.sMin, y + mult);
            }
        }
        return p;
    }
};

struct Work {
    string name;
    vector<Rule> rules;
};

signed main() {
    freopen("input.txt", "r", stdin);
    vector<Part> parts;
    map<string, Work> mp;
    string line;
    while(getline(cin, line)) {
        if(line == "") break;
        int pos = line.find("{");
        Work w;
        w.name = line.substr(0, pos);
        while(pos < line.size()) {
            int np = line.find(",", pos + 1);
            string sub;
            if(np == string::npos) {
                np = sz(line);
                sub = line.substr(pos + 1);
                sub.pop_back();
            } else {
                sub = line.substr(pos + 1, np - pos - 1);
            }
            Rule r;
            r.parse(sub);
            w.rules.pb(r);
            pos = np;
        }
        mp[w.name] = w;
    }
    int ans = 0;
    queue<pair<string, Part> > q;
    Part p;
    q.push({"in", p});
    while(q.size()) {
        auto pp = q.front();
        q.pop();
        string s = pp.fi;
        Part p = pp.se;
        if(s == "A" || s == "R") {
            if(s == "A") {
                int add = p.count();
                ans += p.count();
            }
            continue;
        }
        Work w = mp[s];
        rall(r, w.rules) {
            q.push({r.to, r.apply(p, false)});
            p = r.apply(p, true);
        }
    }
    cout << ans << endl;
    return 0;
}
