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

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        int pos = line.find('[');
        string need = line.substr(pos + 1);
        need.pop_back();
        line = line.substr(0, pos);
        map<char, int> mp;
        int id = 0;
        rall(c, line) {
            if(isalpha(c)) {
                mp[c]++;
            } else if(isdigit(c)) {
                id = 10 * id + c - '0';
            }
        }
        vector<pair<int, char> > v;
        rall(p, mp) {
            v.pb({1000 - p.se, p.fi});
        }
        sort(rng(v));
        string has;
        rep(i, 0, 4) {
            has += v[i].se;
        }
        if(need != has) {
            continue;
        }
        string name;
        rall(c, line) {
            if(isalpha(c)) {
                c = (c - 'a' + id) % 26 + 'a';
                name += c;
            } else if(c == '-') {
                name += " ";
            }
        }
        if(name.find("north") != string::npos) {
            cout << id << endl;
            return 0;
        }
    }
    return 0;
}
