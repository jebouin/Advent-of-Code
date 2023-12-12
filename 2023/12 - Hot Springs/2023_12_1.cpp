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

vector<int> solve(string s) {
    vector<int> v;
    int len = 0;
    rall(c, s) {
        if(c == '#') {
            len++;
        } else {
            if(len > 0) {
                v.pb(len);
                len = 0;
            }
        }
    }
    if(len > 0) {
        v.pb(len);
        len = 0;
    }
    return v;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    int ans = 0;
    while(cin >> s) {
        int cnt = 0;
        rall(c, s) {
            cnt += c == '?';
        }
        string need;
        cin >> need;
        rep(mask, 0, (1LL << cnt) - 1) {
            string t;
            int p = 1;
            rall(c, s) {
                if(c == '?') {
                    c = mask & p ? '#' : '.';
                    p *= 2;
                }
                t += c;
            }
            vector<int> v = solve(t);
            string res;
            int k = sz(v);
            rep(i, 0, k - 1) {
                res += to_string(v[i]);
                if(i < k - 1) {
                    res += ",";
                }
            }
            ans += res == need;
        }
    }
    cout << ans << endl;
    return 0;
}
