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

struct Bot {
    int to1, to2;
    int val1, val2;
    bool out1, out2, sent;

    Bot() {
        val1 = -1;
        val2 = -1;
        sent = false;
    }

    void addVal(int v) {
        if(val1 == -1) {
            val1 = v;
        } else {
            val2 = v;
            if(val1 > val2) {
                swap(val1, val2);
            }
        }
    }

    bool send();
};

const int N = 1'111;
int out[N];
Bot bots[N];
int n;

bool Bot::send() {
    if(val1 == -1 || val2 == -1 || sent) return false;
    if(out1) {
        out[to1] = val1;
    } else {
        bots[to1].addVal(val1);
    }
    if(out2) {
        out[to2] = val2;
    } else {
        bots[to2].addVal(val2);
    }
    sent = true;
    return true;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        string _;
        stringstream ss(line);
        if(line[0] == 'v') {
            int val, bot;
            ss >> _ >> val >> _ >> _ >> _ >> bot;
            bots[bot].addVal(val);
            n = max(n, bot + 1);
        } else {
            int from, to1, to2;
            string type1, type2;
            ss >> _ >> from >> _ >> _ >> _ >> type1 >> to1 >> _ >> _ >> _ >> type2 >> to2;
            bots[from].to1 = to1;
            bots[from].out1 = type1 == "output";
            bots[from].to2 = to2;
            bots[from].out2 = type2 == "output";
            n = max(n, from + 1);
        }
    }
    fill(out, out + N, -1);
    while(1) {
        bool ch = false;
        rep(i, 0, n - 1) {
            if(bots[i].send()) {
                ch = true;
            }
        }
        if(!ch) break;
    }
    int ans = out[0] * out[1] * out[2];
    cout << ans << endl;
    return 0;
}
