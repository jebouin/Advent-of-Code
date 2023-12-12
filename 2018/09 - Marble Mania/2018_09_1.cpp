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
    int n, m;
    string s;
    cin >> n >> s >> s >> s >> s >> s >> m;
    list<int> mar;
    mar.push_back(0);
    list<int>::iterator it = mar.begin();
    vector<int> sc(n, 0);
    rep(i, 0, m - 1) {
        int elf = i % n;
        if((i + 1) % 23 == 0) {
            sc[elf] += i + 1;
            rep(j, 1, 8) {
                if(it == mar.begin()) it = mar.end();
                --it;
            }
            sc[elf] += *it;
            mar.erase(it++);
            if(it == mar.end()) it = mar.begin();
            ++it;
        } else {
            if(mar.size() <= 1) {
                it = mar.begin();
                ++it;
            } else {
                if(it == mar.end()) it = mar.begin();
                ++it;
            }
            mar.insert(it, i + 1);
        }
    }
    int ans = 0;
    rep(i, 0, n - 1) {
        ans = max(ans, sc[i]);
    }
    cout << ans << endl;
    return 0;
}
