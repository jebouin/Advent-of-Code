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

const int N = 111'111;
int mem[N];

signed main() {
    freopen("input.txt", "r", stdin);
    string s, _, t;
    string mask(36, 'X');
    while(cin >> s >> _ >> t) {
        if(s[1] == 'e') {
            int addr = atoi(s.substr(4, sz(s) - 5).c_str());
            int val = atoi(t.c_str());
            rep(i, 0, 35) {
                int p = 1LL << (35 - i);
                if(mask[i] == '0' && (val & p)) {
                    val -= p;
                } else if(mask[i] == '1' && !(val & p)) {
                    val += p;
                }
            }
            mem[addr] = val;
        } else {
            mask = t;
        }
    }
    int ans = 0;
    rep(i, 0, N - 1) {
        ans += mem[i];
    }
    cout << ans << endl;
    return 0;
}
