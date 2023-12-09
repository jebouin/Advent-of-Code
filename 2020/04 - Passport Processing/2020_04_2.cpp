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

bool isValid(map<string, string> mp) {
    if(!(sz(mp) == 8 || (sz(mp) == 7 && mp.find("cid") == mp.end()))) return false;
    int x = atoi(mp["byr"].c_str());
    if(x < 1920 || x > 2002) return false;
    x = atoi(mp["iyr"].c_str());
    if(x < 2010 || x > 2020) return false;
    x = atoi(mp["eyr"].c_str());
    if(x < 2020 || x > 2030) return false;
    string s = mp["hgt"];
    if(sz(s) < 3) return false;
    x = atoi(s.substr(0, sz(s) - 2).c_str());
    if(s.substr(sz(s) - 2) == "cm") {
        if(x < 150 || x > 193) return false;
    } else if(s.substr(s.size() - 2) == "in") {
        if(x < 59 || x > 76) return false;
    } else {
        return false;
    }
    s = mp["hcl"];
    if(sz(s) != 7) return false;
    if(s[0] != '#') return false;
    rep(i, 1, 6) {
        if(!((s[i] >= 'a' && s[i] <= 'f') || isdigit(s[i]))) {
            return false;
        }
    }
    s = mp["ecl"];
    if(s != "amb" && s != "blu" && s != "brn" && s != "gry" && s != "grn" && s != "hzl" && s != "oth") {
        return false;
    }
    s = mp["pid"];
    if(sz(s) != 9) return false;
    rall(c, s) {
        if(!isdigit(c)) {
            return false;
        }
    }
    return true;
}

signed main() {
    freopen("input.txt", "r", stdin);
    map<string, string> mp;
    int ans = 0;
    string line;
    while(getline(cin, line)) {
        if(line == "") {
            ans += isValid(mp);
            mp.clear();
        } else {
            stringstream ss(line);
            string w;
            while(ss >> w) {
                string key = w.substr(0, w.find(":"));
                string val = w.substr(w.find(":") + 1);
                mp[key] = val;
            }
        }
    }
    ans += isValid(mp);
    cout << ans << endl;
    return 0;
}
