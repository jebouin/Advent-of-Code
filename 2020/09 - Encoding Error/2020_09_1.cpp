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
    queue<int> q;
    multiset<int> st;
    int x;
    while(cin >> x) {
        if(sz(st) == 25) {
            vector<int> v(rng(st));
            bool found = false;
            rep(i, 0, 24) {
                rep(j, i + 1, 24) {
                    if(v[i] + v[j] == x) {
                        found = true;
                    }
                }
            }
            if(!found) {
                cout << x << endl;
                return 0;
            }
        }
        st.insert(x);
        q.push(x);
        if(sz(q) > 25) {
            int y = q.front();
            st.erase(st.find(y));
            q.pop();
        }
    }
    return 0;
}
