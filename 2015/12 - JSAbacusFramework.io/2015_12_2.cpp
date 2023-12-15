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

string s;

vector<pair<int, int> > getSegs(int l, int r) {
    vector<pair<int, int> > segs;
    int from = l + 1, level = 0;
    rep(i, l + 1, r - 1) {
        if(s[i] == '[' || s[i] == '{') {
            level++;
        } else if(s[i] == ']' || s[i] == '}') {
            level--;
        }
        if(level == 0 && s[i] == ',') {
            segs.pb({from, i - 1});
            from = i + 1;
        }
    }
    segs.pb({from, r - 1});
    return segs;
}

int solve(int l, int r) {
    if(isdigit(s[l]) || s[l] == '-') {
        int x = 0, sign = 1;
        if(s[l] == '-') {
            sign = -1;
            l++;
        }
        rep(i, l, r) {
            x = 10 * x + s[i] - '0';
        }
        return sign * x;
    } else if(s[l] == '"') {
        return 0;
    } else if(s[l] == '[') {
        vector<pair<int, int> > segs = getSegs(l, r);
        int ans = 0;
        rall(p, segs) {
            int add = solve(p.fi, p.se);
            ans += add;
        }
        return ans;
    } else if(s[l] == '{') {
        vector<pair<int, int> > segs = getSegs(l, r);
        int ans = 0;
        bool red = false;
        rall(p, segs) {
            int colon = p.fi;
            while(s[colon] != ':') {
                colon++;
            }
            string val = s.substr(colon + 2, 3);
            if(val == "red") {
                red = true;
            }
            int add = solve(colon + 1, p.se);
            ans += add;
        }
        return red ? 0 : ans;
    }
    cout << "Can't parse " << s.substr(l, r - l + 1) << endl;
    exit(1);
}

signed main() {
    freopen("input.txt", "r", stdin);
    while(cin >> s) {
        int ans = solve(0, sz(s) - 1);
        cout << ans << endl;
    }
    return 0;
}
