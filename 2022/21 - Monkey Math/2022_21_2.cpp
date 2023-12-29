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

const int N = 11'111;
map<string, vector<string> > mp;
int n, humn;

int solve(string val) {
    if(val == "humn") {
        return humn;
    }
    vector<string>& v = mp[val];
    if(sz(v) == 1) {
        return atoi(v[0].c_str());
    }
    int le = solve(v[0]), ri = solve(v[2]);
    char op = v[1][0];
    if(val == "root") {
        return le - ri;
    }
    if(op == '+') {
        return le + ri;
    } else if(op == '-') {
        return le - ri;
    } else if(op == '*') {
        return le * ri;
    } else if(op == '/') {
        return le / ri;
    }
    exit(1);
}

int f(int x) {
    humn = x;
    return solve("root");
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        string key, w;
        n++;
        ss >> key;
        key = key.substr(0, sz(key) - 1);
        vector<string> v;
        while(ss >> w) {
            v.pb(w);
        }
        mp[key] = v;
    }
    int lo = -(1LL << 50), hi = (1LL << 50);
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int y = f(mid);
        if(y > 0) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
    return 0;
}
