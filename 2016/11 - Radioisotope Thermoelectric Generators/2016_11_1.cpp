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
map<string, int> mp;
int n;

struct State {
    int elevator = 1;
    int mic = 0, gen = 0;

    void addItem(bool isMic, int kind, int f) {
        if(isMic) {
            setMic(kind, f);
        } else {
            setGen(kind, f);
        }
    }
    void setMask(int& x, int kind, int f) {
        x &= ~(3 << (2 * kind));
        x += (f - 1) << (2 * kind);
    }
    void setMic(int kind, int f) {
        setMask(mic, kind, f);
    }
    void setGen(int kind, int f) {
        setMask(gen, kind, f);
    }
    int getMask(int& x, int kind) {
        return ((x >> (2 * kind)) & 3) + 1;
    }
    int getMic(int kind) {
        return getMask(mic, kind);
    }
    int getGen(int kind) {
        return getMask(gen, kind);
    }

    bool isValid() {
        rep(i, 0, n - 1) {
            if(getGen(i) == getMic(i)) continue;
            rep(j, 0, n - 1) {
                if(j != i && getGen(j) == getMic(i)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isDone() {
        rep(i, 0, n - 1) {
            if(getGen(i) != 4 || getMic(i) != 4) return false;
        }
        return true;
    }

    bool operator < (const State& o) const {
        return tie(elevator, mic, gen) < tie(o.elevator, o.mic, o.gen);
    }

    void print() {
        return;
        /*cout << elevator << endl;
        rall(p, gen) {
            cout << p << " ";
        }
        cout << endl;
        rall(p, mic) {
            cout << p << " ";
        }
        cout << endl << endl;*/
    }
};

void addItem(string s) {
    if(mp.find(s) == mp.end()) {
        mp[s] = n++;
    }
}

int ans = 100;
set<State> st;

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    State state;
    int f = 0;
    while(getline(cin, line)) {
        f++;
        stringstream ss(line);
        string s, t;
        while(ss >> s) {
            if(t != "") {
                if(s.substr(0, 9) == "generator") {
                    addItem(t);
                    state.addItem(false, mp[t], f);
                } else if(s.substr(0, 9) == "microchip") {
                    t = t.substr(0, t.find('-'));
                    addItem(t);
                    state.addItem(true, mp[t], f);
                }
            }
            t = s;
        }
    }
    int ans = 1'000'000'000;
    queue<State> q;
    map<State, int> dist;
    q.push(state);
    dist[state] = 0;
    while(sz(q)) {
        State s = q.front();
        q.pop();
        int d = dist[s];
        if(s.isDone()) {
            ans = min(ans, d);
            continue;
        }
        rep(ft, 1, 4) {
            if(abs(ft - s.elevator) != 1) continue;
            rep(i, 0, 2 * n - 1) {
                int fi = i >= n ? s.getGen(i - n) : s.getMic(i);
                if(fi != s.elevator) continue;
                rep(j, i + 1, 2 * n - 1) {
                    int fj = j >= n ? s.getGen(j - n) : s.getMic(j);
                    //if(fj != s.elevator) continue;
                    State t = s;
                    t.elevator = ft;
                    if(i >= n) {
                        t.setGen(i - n, ft);
                    } else {
                        t.setMic(i, ft);
                    }
                    if(fj == s.elevator) {
                        if(j >= n) {
                            t.setGen(j - n, ft);
                        } else {
                            t.setMic(j, ft);
                        }
                    }
                    if(!t.isValid()) continue;
                    int nd = dist.find(t) == dist.end() ? INF : dist[t];
                    if(d + 1 < nd) {
                        dist[t] = d + 1;
                        q.push(t);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
