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

typedef long long ll;
using namespace std;

int readInt() {
    char c;
    bool start = false;
    int ans = 0;
	while(true) {
		c = getchar();
        if(c < '0' || c > '9') {
            if(start) break;
            else continue;
        }
        ans *= 10;
		start = true;
		ans += c - '0';
	}
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    int ans = 0;
    rep(i, 1, 1000) {
        int a = readInt(), b = readInt(), c = readInt(), d = readInt();
        int l = max(a, c), r = min(b, d);
        ans += r - l == min(b - a, d - c);
    }
    cout << ans << endl;
    return 0;
}
