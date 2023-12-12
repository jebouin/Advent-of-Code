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

const int INF = 1'000'000'000;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const int N = 555;
int x[N], y[N], vx[N], vy[N];
int n;

signed main() {
    freopen("input.txt", "r", stdin);
    char c;
    while(cin >> c) {
        n++;
        x[n] = readInt();
        y[n] = readInt();
        vx[n] = readInt();
        vy[n] = readInt();
    }
    rep(k, 1, 1'000'000) {
        set<pair<int, int> > st;
        rep(i, 1, n) {
            x[i] += vx[i];
            y[i] += vy[i];
            st.insert({x[i], y[i]});
        }
        int cnt = 0;
        rall(p, st) {
            bool alone = true;
            rep(d, 0, 3) {
                if(st.find({p.fi + DX[d], p.se + DY[d]}) != st.end()) {
                    alone = false;
                }
            }
            cnt += alone;
        }
        if(cnt <= 20) {
            cout << k << endl;
            break;
        }
    }
    return 0;
}
