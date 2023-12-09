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

#include "../../lib/hash-library/md5.h"

typedef long long ll;
using namespace std;

signed main() {
    freopen("input.txt", "r", stdin);
    string id, ans;
    cin >> id;
    MD5 md5;
    int x = 0;
    while(sz(ans) < 8) {
        string toHash = id + to_string(x);
        string hash = md5(toHash);
        if(hash.substr(0, 5) == "00000") {
            ans += hash[5];
        }
        x++;
    }
    cout << ans << endl;
    return 0;
}
