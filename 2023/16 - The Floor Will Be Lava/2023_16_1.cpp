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

const int DI[] = {0, 1, 0, -1};
const int DJ[] = {1, 0, -1, 0};
const int N = 222;
string grid[N];
bool vis[N][N];
int n, m;

struct State {
    int i = 1, j = 1, dir = 0;

    bool operator < (const State& o) const {
        return tie(i, j, dir) < tie(o.i, o.j, o.dir);
    }

    void move() {
        i += DI[dir];
        j += DJ[dir];
    }

    vector<State> getNext() const {
        vector<State> ans;
        char c = grid[i][j];
        if(c == '-') {
            if(dir == 1 || dir == 3) {
                State t = *this;
                t.dir = 0;
                t.move();
                ans.pb(t);
                t = *this;
                t.dir = 2;
                t.move();
                ans.pb(t);
            } else {
                State t = *this;
                t.move();
                ans.pb(t);
            }
        } else if(c == '|') {
            if(dir == 0 || dir == 2) {
                State t = *this;
                t.dir = 1;
                t.move();
                ans.pb(t);
                t = *this;
                t.dir = 3;
                t.move();
                ans.pb(t);
            } else {
                State t = *this;
                t.move();
                ans.pb(t);
            }
        } else if(c == '/') {
            State t = *this;
            if(dir == 0) t.dir = 3;
            else if(dir == 1) t.dir = 2;
            else if(dir == 2) t.dir = 1;
            else if(dir == 3) t.dir = 0;
            t.move();
            ans.pb(t);
        } else if(c == '\\') {
            State t = *this;
            if(dir == 0) t.dir = 1;
            else if(dir == 1) t.dir = 0;
            else if(dir == 2) t.dir = 3;
            else if(dir == 3) t.dir = 2;
            t.move();
            ans.pb(t);
        } else  {
            State t = *this;
            t.move();
            ans.pb(t);
        }
        return ans;
    }
};

signed main() {
    freopen("input.txt", "r", stdin);
    string str;
    while(cin >> str) {
        grid[++n] = "." + str + ".";
        m = sz(str);
    }
    grid[0] = string(m + 2, '.');
    grid[n + 1] = string(m + 2, '.');
    State s;
    queue<State> q;
    map<State, int> dist;
    q.push(s);
    dist[s] = 0;
    while(sz(q)) {
        State s = q.front();
        q.pop();
        int d = dist[s];
        vis[s.i][s.j] = true;
        if(s.i < 1 || s.j < 1 || s.i > n || s.j > m) continue;
        rall(t, s.getNext()) {
            int nd = dist.find(t) == dist.end() ? 1'000'000 : dist[t];
            if(d + 1 < nd) {
                dist[t] = d + 1;
                q.push(t);
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            ans += vis[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
