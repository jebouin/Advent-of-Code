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
    int pos = 0;
    bool halted = false;

    int operator [] (int i) const {
        return mem[i % sz(mem)];
    }
    int& operator [] (int i) {
        return mem[i % sz(mem)];
    }
    int& getVal(int pos) {
        return (*this)[pos];
    }
    void pb(int x) {mem.pb(x);}
    void step() {
        int op = (*this)[pos];
        int& x = getVal(getVal(pos + 1));
        int& y = getVal(getVal(pos + 2));
        int& z = getVal(getVal(pos + 3));
        if(op == 1) {
            z = x + y;
            pos += 4;
        } else if(op == 2) {
            z = x * y;
            pos += 4;
        } else if(op == 99) {
            halted = true;
        } else {
            cout << "Invalid opcode: " << op << endl;
            exit(1);
        }
    }

    void run() {
        while(!halted) {
            step();
        }
    }
};

signed main() {
    freopen("input.txt", "r", stdin);
    Comp base;
    int x;
    while(cin >> x) {
        getchar();
        base.pb(x);
    }
    rep(x, 0, 99) {
        rep(y, 0, 99) {
            Comp comp = base;
            comp[1] = x;
            comp[2] = y;
            comp.run();
            if(comp[0] == 19690720) {
                cout << 100 * x + y << endl;
                return 0;
            }
        }
    }
    return 0;
}
