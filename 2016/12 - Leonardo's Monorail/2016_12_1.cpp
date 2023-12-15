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

int mem[4];

signed main() {
    freopen("input.txt", "r", stdin);
    vector<string> lines;
    string line;
    while(getline(cin, line)) {
        lines.pb(line);
    }
    int i = 0;
    while(i < sz(lines)) {
        stringstream ss(lines[i]);
        string ins;
        ss >> ins;
        if(ins == "cpy") {
            string from, to;
            ss >> from >> to;
            if(isdigit(from[0])) {
                int val = atoi(from.c_str());
                mem[to[0] - 'a'] = val;
            } else {
                mem[to[0] - 'a'] = mem[from[0] - 'a'];
            }
            i++;
        } else if(ins == "inc" || ins == "dec") {
            string pos;
            ss >> pos;
            mem[pos[0] - 'a'] += ins == "inc" ? 1 : -1;
            i++;
        } else {
            string comp, add;
            ss >> comp >> add;
            if(mem[comp[0] - 'a']) {
                i += atoi(add.c_str());
            } else {
                i++;
            }
        }
    }
    cout << mem[0] << endl;
    return 0;
}
