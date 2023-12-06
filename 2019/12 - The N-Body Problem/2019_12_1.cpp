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

const int N = 111;
int pos[N][3], vel[N][3];
set<vector<pair<int, int> > > st;
int n = 4;

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 1, n) {
        rep(j, 1, 3) getchar();
        cin >> pos[i][0];
        rep(j, 1, 4) getchar();
        cin >> pos[i][1];
        rep(j, 1, 4) getchar();
        cin >> pos[i][2];
        rep(j, 1, 2) getchar();
    }
    rep(step, 1, 1000) {
        rep(c, 0, 2) {
            rep(i, 1, n) {
                rep(j, 1, n) {
                    vel[i][c] += (pos[j][c] > pos[i][c]) - (pos[j][c] < pos[i][c]);
                }
            }
            rep(i, 1, n) {
                pos[i][c] += vel[i][c];
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        int pot = 0, kin = 0;
        rep(j, 0, 2) {
            pot += abs(pos[i][j]);
            kin += abs(vel[i][j]);
        }
        ans += pot * kin;
    }
    cout << ans << endl;
    return 0;
}
