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

#include "../../lib/hash-library/md5.h"

typedef long long ll;
using namespace std;

const int N = 111'111;
string hashes[N];

bool isKey(int pos) {
    if(pos + 1000 >= N) return false;
    string s = hashes[pos];
    int n = sz(s);
    char need = ' ';
    rep(i, 0, n - 3) {
        if(s[i] == s[i + 1] && s[i] == s[i + 2]) {
            need = s[i];
            break;
        }
    }
    if(need == ' ') return false;
    rep(p, pos + 1, pos + 1000) {
        string t = hashes[p];
        int m = sz(t);
        rep(i, 0, m - 5) {
            bool rep = true;
            rep(j, 1, 4) {
                if(t[i] != t[i + j]) {
                    rep = false;
                    break;
                }
            }
            if(rep && t[i] == need) {
                return true;
            }
        }
    }
    return false;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string salt;
    cin >> salt;
    MD5 md5;
    rep(i, 0, N - 1) {
        hashes[i] = md5(salt + to_string(i));
        rep(_, 1, 2016) {
            hashes[i] = md5(hashes[i]);
        }
    }
    int cnt = 0;
    rep(i, 0, N - 1) {
        if(isKey(i)) {
            if(++cnt == 64) {
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
