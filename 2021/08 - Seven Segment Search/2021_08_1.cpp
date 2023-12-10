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

string lit[7] = {
    "1011011111",
    "1000111011",
    "1111100111",
    "0011111011",
    "1010001010",
    "1101111111",
    "1011011011"
};

int solve(vector<string> uniques, vector<string> in) {
    rep(i, 0, sz(uniques) - 1) {
        sort(rng(uniques[i]));
    }
    sort(rng(uniques));
    vector<int> perm(7);
    iota(rng(perm), 0);
    do {
        vector<string> res;
        rep(d, 0, 9) {
            string s;
            rep(c, 0, 6) {
                if(lit[c][d] == '1') {
                    s += perm[c] + 'a';
                }
            }
            sort(rng(s));
            res.pb(s);
        }
        sort(rng(res));
        if(res != uniques) continue;
        int ans = 0;
        rall(w, in) {
            sort(rng(w));
            rep(d, 0, 9) {
                bool ok = true;
                rep(c, 'a', 'g') {
                    if((w.find(perm[c - 'a'] + 'a') != string::npos) ^ (lit[c - 'a'][d] == '1')) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    ans += d == 1 || d == 4 || d == 7 || d == 8;
                }
            }
        }
            return ans;
    } while(next_permutation(rng(perm)));
    cout << "NOT FOUND" << endl;
    exit(1);
    return 0;
}

signed main() {
    freopen("input.txt", "r", stdin);
    int ans = 0;
    string s;
    while(cin >> s) {
        vector<string> uniques(1, s), in;
        rep(i, 1, 9) {
            cin >> s;
            uniques.pb(s);
        }
        cin >> s;
        rep(i, 1, 4) {
            cin >> s;
            in.pb(s);
        }
        int add = solve(uniques, in);
        ans += add;
    }
    cout << ans << endl;
    return 0;
}
