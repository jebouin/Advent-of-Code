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

int readInt(stringstream& ss) {
    char c;
    bool start = false, neg = false;
    int ans = 0;
	while(ss >> c) {
        if((c < '0' || c > '9') && c != '-') {
            if(start) break;
            else continue;
        }
        ans *= 10;
		start = true;
		if(c == '-') neg = true;
		else ans += c - '0';
	}
    return neg ? -ans : ans;
}

inline bool isr(int x) {
    return x >= 0 && x <= 3;
}

int reg[4], regFrom[4], regTo[4];
bool isra[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1};
bool isrb[16] = {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1};

bool execute(int op, int a, int b, int c) {
    if(!isr(c)) return false;
    if(isra[op] && !isr(a)) return false;
    if(isra[op] && !isr(b)) return false;
    if(op == 0) {
        reg[c] = reg[a] + reg[b];
    } else if(op == 1) {
        reg[c] = reg[a] + b;
    } else if(op == 2) {
        reg[c] = reg[a] * reg[b];
    } else if(op == 3) {
        reg[c] = reg[a] * b;
    } else if(op == 4) {
        reg[c] = reg[a] & reg[b];
    } else if(op == 5) {
        reg[c] = reg[a] & b;
    } else if(op == 6) {
        reg[c] = reg[a] | reg[b];
    } else if(op == 7) {
        reg[c] = reg[a] | b;
    } else if(op == 8) {
        reg[c] = reg[a];
    } else if(op == 9) {
        reg[c] = a;
    } else if(op == 10) {
        reg[c] = a > reg[b];
    } else if(op == 11) {
        reg[c] = reg[a] > b;
    } else if(op == 12) {
        reg[c] = reg[a] > reg[b];
    } else if(op == 13) {
        reg[c] = a == reg[b];
    } else if(op == 14) {
        reg[c] = reg[a] == b;
    } else if(op == 15) {
        reg[c] = reg[a] == reg[b];
    }
    return true;
}

void readReg(stringstream& ss, int *reg) {
    rep(i, 0, 3) {
        reg[i] = readInt(ss);
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    int ans = 0;
    while(getline(cin, line)) {
        if(line == "") break;
        int op, a, b, c;
        stringstream ss(line);
        readReg(ss, regFrom);
        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> op >> a >> b >> c;
        getline(cin, line);
        ss.clear();
        ss.str(line);
        readReg(ss, regTo);
        int cnt = 0;
        rep(o, 0, 15) {
            copy(regFrom, regFrom + 4, reg);
            if(execute(o, a, b, c)) {
                bool ok = true;
                rep(i, 0, 3) {
                    if(reg[i] != regTo[i]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    cnt++;
                }
            }
        }
        ans += cnt >= 3;
        getline(cin, line);
    }
    cout << ans << endl;
    return 0;
}
