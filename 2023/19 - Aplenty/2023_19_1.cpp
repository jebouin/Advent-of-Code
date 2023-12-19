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

struct Part {
    int x, m, a, s;
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

    bool test(Part p) {
        if(def) {
            return true;
        }
        int x = 0, y = atoi(val.c_str());
        if(var == "x") x = p.x;
        if(var == "m") x = p.m;
        if(var == "a") x = p.a;
        if(var == "s") x = p.s;
        if(op == "<") return x < y;
        else if(op == ">") return x > y;
        cout << "ERR" << endl;
        exit(1);
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
    while(getline(cin, line)) {
        Part p;
        int pos = line.find("x");
        int com = line.find(",", pos);
        p.x = atoi(line.substr(pos + 2, com - pos - 2).c_str());
        pos = line.find("m");
        com = line.find(",", pos);
        p.m = atoi(line.substr(pos + 2, com - pos - 2).c_str());
        pos = line.find("a");
        com = line.find(",", pos);
        p.a = atoi(line.substr(pos + 2, com - pos - 2).c_str());
        pos = line.find("s");
        com = line.find(",", pos);
        p.s = atoi(line.substr(pos + 2, com - pos - 2).c_str());
        parts.pb(p);
        int add = p.x + p.m + p.a + p.s;
        string s = "in";
        while(s != "R" && s != "A") {
            Work& w = mp[s];
            rall(r, w.rules) {
                if(r.test(p)) {
                    s = r.to;
                    break;
                }
            }
        }
        if(s == "A") {
            ans += add;
        }
    }
    cout << ans << endl;
    return 0;
}
