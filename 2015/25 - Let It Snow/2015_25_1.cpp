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
    bool start = false;
    int ans = 0;
	while(true) {
		c = getchar();
        if(isdigit(c)) {
            ans = 10 * ans + c - '0';
            start = true;
        } else if(start) {
            break;
        }
	}
    return ans;
}

const int N = 11'111;
int a[N][N];

signed main() {
    freopen("input.txt", "r", stdin);
    int row = readInt(), col = readInt();
    int diag = 1, pos = 1;
    int code = 20151125, mult = 252533, mod = 33554393;
    while(!a[row][col]) {
        a[diag - pos + 1][pos] = code;
        code = code * mult % mod;
        if(pos == diag) {
            diag++;
            pos = 1;
        } else {
            pos++;
        }
    }
    cout << a[row][col] << endl;
    return 0;
}
