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

int reg[6], opr;
vector<string> ops;
vector<int> opa, opb, opc;

bool execute(string op, int a, int b, int c) {
    if(op == "addr") {
        reg[c] = reg[a] + reg[b];
    } else if(op == "addi") {
        reg[c] = reg[a] + b;
    } else if(op == "mulr") {
        reg[c] = reg[a] * reg[b];
    } else if(op == "muli") {
        reg[c] = reg[a] * b;
    } else if(op == "banr") {
        reg[c] = reg[a] & reg[b];
    } else if(op == "bani") {
        reg[c] = reg[a] & b;
    } else if(op == "borr") {
        reg[c] = reg[a] | reg[b];
    } else if(op == "bori") {
        reg[c] = reg[a] | b;
    } else if(op == "setr") {
        reg[c] = reg[a];
    } else if(op == "seti") {
        reg[c] = a;
    } else if(op == "gtir") {
        reg[c] = a > reg[b];
    } else if(op == "gtri") {
        reg[c] = reg[a] > b;
    } else if(op == "gtrr") {
        reg[c] = reg[a] > reg[b];
    } else if(op == "eqir") {
        reg[c] = a == reg[b];
    } else if(op == "eqri") {
        reg[c] = reg[a] == b;
    } else if(op == "eqrr") {
        reg[c] = reg[a] == reg[b];
    }
    return true;
}

// After inspecting the registers it looks like r3 stops on a small value for p1 and a large value for p2 which makes the program take a lot longer to run. Let's see what happens if we set it to different small values.
int getGoal() {
    fill(reg, reg + 6, 0);
    reg[0] = 1;
    int prev = -1, cnt = 0;
    while(cnt < 10) {
        int pc = reg[opr];
        execute(ops[pc], opa[pc], opb[pc], opc[pc]);
        reg[opr]++;
        if(reg[3] != prev) {
            cnt = 1;
            prev = reg[3];
        } else {
            cnt++;
        }
    }
    return reg[3];
}

int run(int r3) {
    int goal = getGoal();
    fill(reg, reg + 6, 0);
    reg[0] = 1;
    while(reg[opr] < sz(ops)) {
        int pc = reg[opr];
        execute(ops[pc], opa[pc], opb[pc], opc[pc]);
        reg[opr]++;
        if(reg[3] == goal) {
            reg[3] = r3;
        }
    }
    return reg[0];
}

//https://oeis.org/A000203
int solve(int x) {
    int ans = 0;
    for(int d = 1; d * d <= x; d++) {
        if(x % d == 0) {
            ans += d;
            if(x / d != d) {
                ans += x / d;
            }
        }
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s >> opr;
    while(cin >> s) {
        int a, b, c;
        cin >> a >> b >> c;
        ops.pb(s);
        opa.pb(a);
        opb.pb(b);
        opc.pb(c);
    }
    int ans = solve(getGoal());
    cout << ans << endl;
    return 0;
}
