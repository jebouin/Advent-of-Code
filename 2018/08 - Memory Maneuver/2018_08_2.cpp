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

struct Node {
    vector<Node*> children;
    vector<int> meta;

    void read() {
        int cnt, mc;
        cin >> cnt >> mc;
        rep(i, 1, cnt) {
            children.pb(new Node());
            children.back()->read();
        }
        rep(i, 1, mc) {
            int x;
            cin >> x;
            meta.pb(x);
        }
    }

    int getVal() {
        int ans = 0;
        if(children.empty()) {
            rall(x, meta) {
                ans += x;
            }
        } else {
            rall(x, meta) {
                if(x >= 1 && x <= (int)children.size()) {
                    ans += children[x - 1]->getVal();
                }
            }
        }
        return ans;
    }
};

signed main() {
    freopen("input.txt", "r", stdin);
    Node root;
    root.read();
    int ans = root.getVal();
    cout << ans << endl;
    return 0;
}
