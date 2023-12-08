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
    string s;
    cin >> s;
    set<string> all;
    map<string, string> ml, mr;
    string from, x, w;
    while(cin >> from) {
        cin >> w >> w;
        w = w.substr(1, 3);
        ml[from] = w;
        cin >> w;
        w = w.substr(0, 3);
        mr[from] = w;
        all.insert(from);
    }
    int ans = 1;
    rall(cur, all) {
        if(cur[2] != 'A') continue;
        set<pair<string, int> > vis;
        vector<int> times;
        int i = 0, t = 0;
        while(vis.find({cur, i}) == vis.end()) {
            vis.insert({cur, i});
            if(cur[2] == 'Z') {
                times.pb(t);
            }
            char dir = s[i];
            if(dir == 'L') {
                cur = ml[cur];
            } else {
                cur = mr[cur];
            }
            i++;
            if(i == sz(s)) {
                i = 0;
            }
            t++;
        }
        ans = ans * times[0] / __gcd(ans, times[0]);
    }
    cout << ans << endl;
    return 0;
}
