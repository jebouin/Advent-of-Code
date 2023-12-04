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

const string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    int ans = 0;
    while(cin >> s) {
        int n = sz(s);
        vector<int> digits;
        rep(i, 0, n - 1) {
            if(isdigit(s[i])) {
                digits.pb(s[i] - '0');
            } else {
                rep(d, 0, 9) {
                    if(s.substr(i, sz(words[d])) == words[d]) {
                        digits.pb(d);
                    }
                }
            }
        }
        int add = digits[0] * 10 + digits[sz(digits) - 1];
        ans += add;
    }
    cout << ans << endl;
    return 0;
}
