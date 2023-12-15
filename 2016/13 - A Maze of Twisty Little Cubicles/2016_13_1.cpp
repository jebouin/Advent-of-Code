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

const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
int in;

bool isWall(int x, int y) {
    int sum = x * x + 3 * x + 2 * x * y + y + y * y + in;
    return pcnt(sum) % 2;
}

signed main() {
    freopen("input.txt", "r", stdin);
    cin >> in;
    int tx = 31, ty = 39;
    map<pair<int, int>, int> dist;
    queue<pair<int, int> > q;
    dist[{1, 1}] = 0;
    q.push({1, 1});
    rep(_, 0, 1'000'000) {
        if(q.empty()) break;
        pair<int, int> pos = q.front();
        q.pop();
        rep(d, 0, 3) {
            int xx = pos.fi + DX[d];
            int yy = pos.se + DY[d];
            if(xx < 0 || yy < 0 || isWall(xx, yy)) continue;
            int nd = dist.find({xx, yy}) == dist.end() ? 1'000'000 : dist[{xx, yy}];
            if(dist[pos] + 1 < nd) {
                dist[{xx, yy}] = dist[pos] + 1;
                q.push({xx, yy});
            }
        }
    }
    cout << dist[{tx, ty}] << endl;
    return 0;
}
