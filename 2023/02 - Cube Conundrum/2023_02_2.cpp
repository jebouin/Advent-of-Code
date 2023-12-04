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

typedef long long ll;
using namespace std;

signed main() {
    freopen("input.txt", "r", stdin);
    int ans = 0;
    rep(i, 1, 100) {
        int maxr = 0, maxg = 0, maxb = 0;
        string line;
        getline(cin, line);
        stringstream ss(line);
        string w;
        ss >> w >> w;
        bool endLine = false;
        while(!endLine) {
            int r = 0, g = 0, b = 0;
            bool endGroup = false;
            while(!endGroup) {
                int cnt;
                ss >> cnt >> w;
                if(isalpha(w.back())) {
                    endGroup = true;
                    endLine = true;
                } else {
                    if(w.back() == ';') {
                        endGroup = true;
                    }
                    w.pop_back();
                }
                if(w == "red") r = cnt;
                if(w == "green") g = cnt;
                if(w == "blue") b = cnt;
                maxr = max(maxr, r);
                maxg = max(maxg, g);
                maxb = max(maxb, b);
            }
        }
        ans += maxr * maxg * maxb;
    }
    cout << ans << endl;
    return 0;
}
