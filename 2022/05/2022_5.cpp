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
string a[N] = {"", "BGSC", "TMWHJNVG", "MQS", "BSLTWNM", "JZFTVGWP", "CTBGQHS", "TJPBW", "GDCZFTQM", "NSHBPF"};

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 1, 501) {
        string s;
        int k, x, y;
        cin >> s >> k >> s >> x >> s >> y;
        int kk = k;
        string t;
        while(kk--) {
            char c = a[x].back();
            a[x].pop_back();
            t += c;
        }
        kk = k;
        reverse(rng(t));
        a[y] += t;
    }
    rep(i, 1, 9) {
        cout << a[i].back();
    }
    cout << endl;
    return 0;
}
