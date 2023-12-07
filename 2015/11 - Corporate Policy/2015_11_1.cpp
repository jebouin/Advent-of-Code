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

int n;

bool isValid(string s) {
    bool hasStraight = false, hasPairs = false;
    rall(c, s) {
        if(c == 'i' || c == 'o' || c == 'l') {
            return false;
        }
    }
    rep(i, 0, n - 3) {
        if(s[i + 1] == s[i] + 1 && s[i + 2] == s[i] + 2) {
            hasStraight = true;
        }
    }
    rep(i, 0, n - 4) {
        rep(j, i + 2, n - 2) {
            if(s[i] == s[i + 1] && s[j] == s[j + 1] && s[i] != s[j]) {
                hasPairs = true;
            }
        }
    }
    return hasStraight && hasPairs;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string w;
    cin >> w;
    n = sz(w);
    while(!isValid(w)) {
        w[n - 1]++;
        int i = n - 1;
        while(i > 0 && w[i] == 'z' + 1) {
            w[i] = 'a';
            w[i - 1]++;
            i--;
        }
    }
    cout << w << endl;
    return 0;
}
