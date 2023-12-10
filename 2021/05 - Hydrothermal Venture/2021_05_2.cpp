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

int readInt() {
    char c;
    bool start = false, neg = false;
    int ans = 0;
	while(true) {
		c = getchar();
        if((c < '0' || c > '9') && c != '-') {
            if(start) break;
            else continue;
        }
        ans *= 10;
		start = true;
		if(c == '-') neg = true;
		else ans += c - '0';
	}
    return neg ? -ans : ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    set<pair<int, int> > st;
    string s;
    char c;
    int x1, y1, x2, y2;
    map<pair<int, int>, int> mp;
    while(cin >> x1) {
        cin >> c >> y1 >> s >> x2 >> c >> y2;
        if(x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if(x1 == x2) {
            rep(y, min(y1, y2), max(y1, y2)) {
                mp[{x1, y}]++;
            }
        } else if(y1 == y2) {
            rep(x, x1, x2) {
                mp[{x, y1}]++;
            }
        } else {
            rep(x, x1, x2) {
                int d = x - x1;
                mp[{x, y1 < y2 ? y1 + d : y1 - d}]++;
            }
        }
    }
    int ans = 0;
    rall(p, mp) {
        ans += p.se > 1;
    }
    cout << ans << endl;
    return 0;
}
