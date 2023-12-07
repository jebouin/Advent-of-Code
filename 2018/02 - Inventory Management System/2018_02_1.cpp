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

const int N = 111;

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    int cnt2 = 0, cnt3 = 0;
    while(cin >> s) {
        map<char, int> mp;
        rall(c, s) {
            mp[c]++;
        };
        bool has2 = false, has3 = false;
        rall(p, mp) {
            has2 |= p.se == 2;
            has3 |= p.se == 3;
        }
        cnt2 += has2;
        cnt3 += has3;
    }
    int ans = cnt2 * cnt3;
    cout << ans << endl;
    return 0;
}
