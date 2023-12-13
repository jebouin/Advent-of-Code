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

const int N = 11;
int cap[N], dur[N], fla[N], tex[N], cal[N];
int n;

int solve(vector<int>& v, int rem) {
    if(sz(v) == n) {
        int a = 0, b = 0, c = 0, d = 0;
        rep(i, 1, n) {
            a += cap[i] * v[i - 1];
            b += dur[i] * v[i - 1];
            c += fla[i] * v[i - 1];
            d += tex[i] * v[i - 1];
        }
        if(a < 0) a = 0;
        if(b < 0) b = 0;
        if(c < 0) c = 0;
        if(d < 0) d = 0;
        return a * b * c * d;
    }
    int ans = 0;
    rep(i, 0, rem) {
        v.pb(i);
        int cur = solve(v, rem - i);
        ans = max(ans, cur);
        v.pop_back();
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        n++;
        cap[n] = readInt();
        dur[n] = readInt();
        fla[n] = readInt();
        tex[n] = readInt();
        cal[n] = readInt();
    }
    vector<int> v;
    int ans = solve(v, 100);
    cout << ans << endl;
    return 0;
}

