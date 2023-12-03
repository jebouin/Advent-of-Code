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

const int N = 11;
string a[N];
int n = 9;

signed main() {
    freopen("input.txt", "r", stdin);
    rep(j, 1, n) {
        a[j] = string(8, ' ');
    }
    string line;
    rep(i, 1, 8) {
        getline(cin, line);
        rep(j, 1, n) {
            a[j][i - 1] = line[(j - 1) * 4 + 1];
        }
    }
    rep(j, 1, n) {
        reverse(rng(a[j]));
        while(a[j].back() == ' ') {
            a[j].pop_back();
        }
    }
    getline(cin, line);
    string w;
    while(cin >> w) {
        int k, x, y;
        cin >> k >> w >> x >> w >> y;
        rep(_, 1, k) {
            char c = a[x].back();
            a[x].pop_back();
            a[y] += c;
        }
    }
    rep(i, 1, 9) {
        cout << a[i].back();
    }
    cout << endl;
    return 0;
}
