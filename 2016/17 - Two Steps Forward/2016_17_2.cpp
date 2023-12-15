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

#include "../../lib/hash-library/md5.h"

typedef long long ll;
using namespace std;

const string DIRS = "UDLR";
const int DI[] = {-1, 1, 0, 0};
const int DJ[] = {0, 0, -1, 1};
string code;
int ans = 0;
MD5 md5;

void solve(string s, int i, int j) {
    if(i == 4 && j == 4) {
        ans = max(ans, sz(s));
        return;
    }
    string hash = md5(code + s);
    rep(d, 0, 3) {
        int ii = i + DI[d];
        int jj = j + DJ[d];
        if(ii < 1 || jj < 1 || ii > 4 || jj > 4) continue;
        char c = hash[d];
        if((c >= '0' && c <= '9') || c == 'a') continue;
        string t = s + DIRS[d];
        solve(t, ii, jj);
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    cin >> code;
    string s;
    solve(s, 1, 1);
    cout << ans << endl;
    return 0;
}
