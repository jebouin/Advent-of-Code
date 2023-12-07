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

string ord = "AKQT98765432J";

int getRank(string& s, int i = 0) {
    map<char, int> mp;
    rall(c, s) {
        mp[c]++;
    }
    vector<int> occ;
    rall(p, mp) {
        occ.pb(p.se);
    }
    sort(rng(occ), std::greater<int>());
    if(i == 5) {
        if(occ[0] == 5) return 7;
        if(occ[0] == 4) return 6;
        if(occ[0] == 3 && occ[1] == 2) return 5;
        if(occ[0] == 3) return 4;
        if(occ[0] == 2 && occ[1] == 2) return 3;
        if(occ[0] == 2) return 2;
        return 1;
    }
    if(s[i] == 'J') {
        int maxi = 0;
        rall(c, ord) {
            char prev = s[i];
            s[i] = c;
            int cur = getRank(s, i + 1);
            maxi = max(maxi, cur);
            s[i] = prev;
        }
        return maxi;
    } else {
        return getRank(s, i + 1);
    }
}

bool comp(const pair<string, int>& p, const pair<string, int>& q) {
    string s = p.fi, t = q.fi;
    int r = getRank(s), rr = getRank(t);
    if(r != rr) return r < rr;
    rep(i, 0, 4) {
        if(s[i] != t[i]) {
            return ord.find(s[i]) > ord.find(t[i]);
        }
    }
    return false;
}

signed main() {
    freopen("input.txt", "r", stdin);
    vector<pair<string, int>> v;
    string s;
    while(cin >> s) {
        int x;
        cin >> x;
        v.pb({s, x});
    }
    sort(rng(v), comp);
    int ans = 0;
    rep(i, 0, sz(v)) {
        int add = (i + 1) * v[i].se;
        ans += add;
    }
    cout << ans << endl;
    return 0;
}
