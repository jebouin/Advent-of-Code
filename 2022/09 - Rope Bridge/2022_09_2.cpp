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

pair<int, int> move(int hx, int hy, int tx, int ty) {
    if(tx < hx - 1) {
        if(ty < hy) {
            ty++;
        } else if(ty > hy) {
            ty--;
        }
        tx++;
    } else if(tx > hx + 1) {
        if(ty < hy) {
            ty++;
        } else if(ty > hy) {
            ty--;
        }
        tx--;
    }
    if(ty < hy - 1) {
        if(tx < hx) {
            tx++;
        } else if(tx > hx) {
            tx--;
        }
        ty++;
    } else if(ty > hy + 1) {
        if(tx < hx) {
            tx++;
        } else if(tx > hx) {
            tx--;
        }
        ty--;
    }
    return {tx, ty};
}

signed main() {
    freopen("input.txt", "r", stdin);
    set<pair<int, int> > st;
    vector<pair<int, int> > knots(10, {0, 0});
    st.insert({0, 0});
    string dir;
    int cnt;
    while(cin >> dir >> cnt) {
        while(cnt > 0) {
            if(dir == "L") {
                knots[0].fi--;
            } else if(dir == "R") {
                knots[0].fi++;
            } else if(dir == "U") {
                knots[0].se--;
            } else {
                knots[0].se++;
            }
            rep(i, 1, 9) {
                knots[i] = move(knots[i - 1].fi, knots[i - 1].se, knots[i].fi, knots[i].se);
            }
            cnt--;
            st.insert(knots.back());
        }
    }
    cout << sz(st) << endl;
    return 0;
}
