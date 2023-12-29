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
#define rall(x,a) for(auto& x : a)
#define MOD 1000000007
#ifndef LOCAL
#define endl "\n"
#define cerr if(0) cerr
#endif
#define int long long

typedef long long ll;
using namespace std;

struct Mod {
    string name;
    char type;
    vector<string> to;
    map<string, bool> prev;
    queue<pair<string, bool> > q;
    bool on = false;

    bool read() {
        string line;
        if(!getline(cin, line)) {
            return false;
        }
        stringstream ss(line);
        string s;
        ss >> s;
        if(isalpha(s[0])) {
            type = 'b';
            name = s;
        } else {
            type = s[0];
            name = s.substr(1);
        }
        ss >> s;
        while(ss >> s) {
            if(s.back() == ',') {
                s.pop_back();
            }
            to.pb(s);
        }
        return true;
    }

    bool update() {
        if(q.empty()) return false;
        while(sz(q)) {
            auto p = q.front();
            q.pop();
            string from = p.fi;
            bool b = p.se;
            if(type == '%') {
                if(!b) {
                    on = !on;
                    send(on);
                }
            } else if(type == '&') {
                prev[from] = b;
                bool ok = true;
                rall(p, prev) {
                    ok &= p.se;
                }
                send(!ok);
            } else if(type == 'b') {
                send(b);
            }
        }
        return true;
    }

    void send(bool b);
};

queue<string> toup;
map<string, Mod> mp;

void Mod::send(bool b) {
    rall(s, to) {
        Mod& m = mp[s];
        m.q.push({name, b});
        toup.push(s);
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    Mod mod;
    while(mod.read()) {
        mp[mod.name] = mod;
        mod = Mod();
    }
    rall(p, mp) {
        Mod& m = p.se;
        rall(s, m.to) {
            Mod& mm = mp[s];
            mm.prev[m.name] = false;
        }
    }
    set<pair<string, int> > st;
    int cnt = 0;
    rep(i, 1, 20'000) {
        bool ch = false;
        rall(p, mp) {
            if(p.se.update()) {
                ch = true;
            }
            while(toup.size()) {
                string s = toup.front();
                toup.pop();
                mp[s].update();
                rall(p, mp["gf"].prev) {
                    if(p.se) {
                        st.insert({p.fi, cnt});
                    }
                }
            }
        }
        if(!ch) {
            mp["broadcaster"].q.push({"button", false});
            cnt++;
        }
    }
    set<string> seen;
    int ans = 1;
    rall(p, st) {
        if(seen.find(p.fi) != seen.end()) continue;
        seen.insert(p.fi);
        int g = __gcd(ans, p.se);
        ans = ans / g * p.se;
    }
    cout << ans << endl;
    return 0;
}
