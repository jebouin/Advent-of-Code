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

bool isValid(map<string, string> mp) {
    return sz(mp) == 8 || (sz(mp) == 7 && mp.find("cid") == mp.end());
}

signed main() {
    freopen("input.txt", "r", stdin);
    map<string, string> mp;
    int ans = 0;
    string line;
    while(getline(cin, line)) {
        if(line == "") {
            ans += isValid(mp);
            mp.clear();
        } else {
            stringstream ss(line);
            string w;
            while(ss >> w) {
                string key = w.substr(0, w.find(":"));
                string val = w.substr(w.find(":") + 1);
                mp[key] = val;
            }
        }
    }
    ans += isValid(mp);
    cout << ans << endl;
    return 0;
}
