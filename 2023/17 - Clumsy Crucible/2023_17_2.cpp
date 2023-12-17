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
const int DI[] = {0, 1, 0, -1};
const int DJ[] = {1, 0, -1, 0};
const int N = 222;
string grid[N];
int n, m;

struct State {
    int i = 1, j = 1, dir = 0, cnt = 0, heat = 0;

    bool operator < (const State& o) const {
        return tie(i, j, dir, cnt) < tie(o.i, o.j, o.dir, o.cnt);
    }

    void move() {
        i += DI[dir];
        j += DJ[dir];
        cnt++;
        if(isValid()) {
            heat += grid[i][j] - '0';
        }
    }

    void turn(int sign) {
        dir = ((dir + sign) % 4 + 4) % 4;
        cnt = 0;
    }

    bool isValid() {
        return i >= 1 && i <= n && j >= 1 && j <= m && cnt <= 10;
    }

    vector<pair<State, int> > getNext() const {
        vector<pair<State, int> > ans;
        State t = *this;
        t.move();
        if(t.isValid()) ans.pb({t, grid[t.i][t.j] - '0'});
        if(cnt >= 4) {
            t = *this;
            t.turn(1);
            t.move();
            if(t.isValid()) ans.pb({t, grid[t.i][t.j] - '0'});
            t = *this;
            t.turn(-1);
            t.move();
            if(t.isValid()) ans.pb({t, grid[t.i][t.j] - '0'});
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
    queue<State> q;
    map<State, int> dist;
    set<State> inq;
    State s;
    s.i = 1;
    s.j = 1;
    s.dir = 0;
    q.push(s);
    dist[s] = 0;
    inq.insert(s);
    s.dir = 1;
    q.push(s);
    dist[s] = 0;
    inq.insert(s);
    while(sz(q)) {
        State s = q.front();
        q.pop();
        inq.erase(s);
        rall(p, s.getNext()) {
            int nd = dist.find(p.fi) == dist.end() ? 1'000'000 : dist[p.fi];
            if(dist[s] + p.se < nd) {
                dist[p.fi] = dist[s] + p.se;
                if(inq.find(p.fi) == inq.end()) {
                    q.push(p.fi);
                }
            }
        }
    }
    int ans = INF;
    rall(p, dist) {
        if(p.fi.i == n && p.fi.j == m) {
            ans = min(ans, p.se);
        }
    }
    cout << ans << endl;
    return 0;
}
