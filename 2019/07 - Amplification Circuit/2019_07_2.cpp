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

typedef long long ll;
using namespace std;

struct Comp {
    vector<int> mem;
    queue<int> in, out;
    int pos = 0;
    bool halted = false;

    void load() {
        int x;
        while(cin >> x) {
            getchar();
            mem.pb(x);
        }
        mem.resize(1'000'000);
    }
    int operator [] (int i) const {
        return mem[i];
    }
    int& operator [] (int i) {
        return mem[i];
    }
    int& getVal(int pos, int mode) {
        int& x = (*this)[pos];
        return mode == 0 ? (*this)[x] : x;
    }
    void pb(int x) {mem.pb(x);}
    void input(int x) {
        in.push(x);
    }
    bool output(int &x) {
        if(out.empty()) {
            return false;
        }
        x = out.front();
        out.pop();
        return true;
    }
    void step() {
        int val = (*this)[pos];
        int op = val % 100;
        int m1 = val / 100 % 10, m2 = val / 1000 % 10, m3 = val / 10000 % 10;
        int& x = getVal(pos + 1, m1);
        int& y = getVal(pos + 2, m2);
        int& z = getVal(pos + 3, m3);
        if(op == 1) {
            z = x + y;
            pos += 4;
        } else if(op == 2) {
            z = x * y;
            pos += 4;
        } else if(op == 3) {
            x = in.front();
            in.pop();
            pos += 2;
        } else if(op == 4) {
            out.push(x);
            pos += 2;
        } else if(op == 5) {
            if(x) pos = y;
            else pos += 3;
        } else if(op == 6) {
            if(!x) pos = y;
            else pos += 3;
        } else if(op == 7) {
            z = x < y;
            pos += 4;
        } else if(op == 8) {
            z = x == y;
            pos += 4;
        } else if(op == 99) {
            halted = true;
        } else {
            cout << "Invalid opcode: " << op << endl;
            exit(1);
        }
    }

    void run(bool stopOnOutput) {
        while(!halted) {
            if(sz(out) > 0 && stopOnOutput) {
                break;
            }
            step();
        }
    }
};

signed main() {
    freopen("input.txt", "r", stdin);
    Comp base;
    base.load();
    vector<int> perm;
    rep(i, 5, 9) {
        perm.pb(i);
    }
    int ans = 0;
    do {
        vector<Comp> comps(5, base);
        rep(i, 0, 4) {
            comps[i].input(perm[i]);
        }
        int power = 0;
        do {
            rep(i, 0, 4) {
                comps[i].input(power);
                comps[i].run(true);
                comps[i].output(power);
            }
        } while(!comps[4].halted);
        ans = max(ans, power);
    } while(next_permutation(rng(perm)));
    cout << ans << endl;
    return 0;
}
