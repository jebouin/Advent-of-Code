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

const int DI[] = {-1, 0, 1, 0};
const int DJ[] = {0, 1, 0, -1};
const string CH = "wifc";

signed main() {
    freopen("input.txt", "r", stdin);
    map<pair<int, int>, char> mp;
    string s;
    int n = 0, m = 0;
    while(cin >> s) {
        m = sz(s);
        n++;
        rep(j, 1, m) {
            mp[{n, j}] = s[j - 1] == '.' ? 'c' : 'i';
        }
    }
    int i = (n + 1) / 2, j = (m + 1) / 2, d = 0;
    int ans = 0;
    rep(o, 1, 10000000) {
        char c = mp.find({i, j}) != mp.end() ? mp[{i, j}] : 'c';
        ans += c == 'w';
        int pos = CH.find(c);
        d = (d + pos) % 4;
        mp[{i, j}] = CH[(pos + 1) % 4];
        i += DI[d];
        j += DJ[d];
    }
    cout << ans << endl;
    return 0;
}
