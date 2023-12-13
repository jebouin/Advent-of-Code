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

const int N = 111;
int speed[N], dur[N], rest[N], timer[N], dist[N];
bool resting[N];
int n;

signed main() {
    freopen("input.txt", "r", stdin);
    char c;
    while(cin >> c) {
        n++;
        speed[n] = readInt();
        dur[n] = readInt();
        rest[n] = readInt();
        string s;
        cin >> s;
    }
    rep(t, 1, 2503) {
        rep(i, 1, n) {
            timer[i]++;
            if(resting[i]) {
                if(timer[i] == rest[i]) {
                    timer[i] = 0;
                    resting[i] = false;
                }
            } else {
                dist[i] += speed[i];
                if(timer[i] == dur[i]) {
                    timer[i] = 0;
                    resting[i] = true;
                }
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        ans = max(ans, dist[i]);
    }
    cout << ans << endl;
    return 0;
}
