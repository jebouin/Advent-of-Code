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

const string DIRS = "WNES";
const int DY[] = {0, -1, 0, 1};
const int DX[] = {-1, 0, 1, 0};

signed main() {
    freopen("input.txt", "r", stdin);
    int x = 10, y = -1;
    int sx = 0, sy = 0;
    string s;
    while(cin >> s) {
        char c = s[0];
        int cnt = atoi(s.substr(1).c_str());
        if(c == 'L' || c == 'R') {
            rep(i, 1, cnt / 90) {
                int temp = x;
                if(c == 'R') {
                    x = -y;
                    y = temp;
                } else {
                    x = y;
                    y = -temp;
                }
            }
        } else if(c == 'F') {
            sx += cnt * x;
            sy += cnt * y;
        } else {
            int dir = DIRS.find(c);
            x += cnt * DX[dir];
            y += cnt * DY[dir];
        }
    }
    int ans = abs(sx) + abs(sy);
    cout << ans << endl;
    return 0;
}
