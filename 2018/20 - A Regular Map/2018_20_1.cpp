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

const int INF = 1'000'000'000;
const int N = 11'111;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
bool grid[N][N];
int dist[N][N];

set<pair<pair<int, int>, int> > memo;
void build(const string& s, int x, int y, int& i) {
    pair<pair<int, int>, int> key(make_pair(x, y), i);
    if(memo.find(key) != memo.end()) return;
    memo.insert(key);
    if(s[i] == '$') return;
    else if(s[i] == '^') i++;
    else if(s[i] == 'W') grid[x][--y] = true, grid[x][--y] = true, i++;
    else if(s[i] == 'E') grid[x][++y] = true, grid[x][++y] = true, i++;
    else if(s[i] == 'N') grid[--x][y] = true, grid[--x][y] = true, i++;
    else if(s[i] == 'S') grid[++x][y] = true, grid[++x][y] = true, i++;
    else if(s[i] == '(') {
        do {
            build(s, x, y, ++i);
        } while(s[i] == '|');
        assert(s[i] == ')');
        ++i;
    }
    build(s, x, y, i);
}

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 0, N - 1) {
        fill(dist[i], dist[i] + N, INF);
    }
    string s;
    cin >> s;
    int x = N / 2, y = N / 2, i = 1;
    grid[x][y] = true;
    build(s, x, y, i);
    queue<pair<int, int> > q;
    dist[x][y] = 0;
    q.push(make_pair(x, y));
    int ans = 0;
    while(sz(q)) {
        pair<int, int> pos = q.front();
        int di = dist[pos.first][pos.second];
        ans = max(ans, di / 2);
        q.pop();
        rep(d, 0, 3) {
            int nx = pos.first + DX[d];
            int ny = pos.second + DY[d];
            if(grid[nx][ny] && dist[nx][ny] > di + 1) {
                dist[nx][ny] = di + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    cout << ans << endl;
    return 0;
}

