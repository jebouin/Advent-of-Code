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

int solve(string s) {
    int x = 0;
    rall(c, s) {
        x += c;
        x = (x * 17) % 256;
    }
    return x;
}

vector<pair<string, int> > boxes[256];

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int pos = 0;
    vector<string> v;
    while(pos < sz(s)) {
        int np = s.find(",", pos);
        if(np == (int)string::npos) np = sz(s);
        string sub = s.substr(pos, np - pos);
        v.pb(sub);
        pos = np + 1;
    }
    set<string> all;
    rall(s, v) {
        int signPos = 0;
        while(s[signPos] != '-' && s[signPos] != '=') {
            signPos++;
        }
        string sub = s.substr(0, signPos);
        vector<pair<string, int> >& box = boxes[solve(sub)];
        all.insert(sub);
        int slot = -1;
        rep(i, 0, sz(box) - 1) {
            if(box[i].fi == sub) {
                slot = i;
            }
        }
        if(s[signPos] == '-') {
            if(slot != -1) {
                box.erase(box.begin() + slot);
            }
        } else {
            int foc = s[signPos + 1] - '0';
            if(slot != -1) {
                box[slot].se = foc;
            } else {
                box.pb({sub, foc});
            }
        }
    }
    int ans = 0;
    rall(s, all) {
        int add = 1, box = -1, slot = -1, foc = -1;
        rep(b, 0, 255) {
            rep(i, 0, sz(boxes[b]) - 1) {
                if(boxes[b][i].fi == s) {
                    box = b + 1;
                    foc = boxes[b][i].se;
                    slot = i + 1;
                }
            }
        }
        if(box != -1) {
            add *= box * slot * foc;
            ans += add;
        }
    }
    cout << ans << endl;
    return 0;
}
