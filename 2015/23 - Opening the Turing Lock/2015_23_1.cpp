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
    map<string, int> mem;
    vector<string> lines;
    string s, line, reg;
    while(getline(cin, line)) {
        lines.pb(line);
    }
    int i = 0;
    while(i >= 0 && i < sz(lines)) {
        stringstream ss(lines[i]);
        ss >> s;
        if(s == "hlf") {
            ss >> reg;
            mem[reg] /= 2;
            i++;
        } else if(s == "tpl") {
            ss >> reg;
            mem[reg] *= 3;
            i++;
        } else if(s == "inc") {
            ss >> reg;
            mem[reg]++;
            i++;
        } else if(s == "jmp") {
            int off;
            ss >> off;
            i += off;
        } else if(s == "jie") {
            int off;
            ss >> reg >> off;
            reg.pop_back();
            if(mem[reg] % 2 == 0) {
                i += off;
            } else {
                i++;
            }
        } else if(s == "jio") {
            int off;
            ss >> reg >> off;
            reg.pop_back();
            if(mem[reg] == 1) {
                i += off;
            } else {
                i++;
            }
        }
    }
    cout << mem["b"] << endl;
    return 0;
}
