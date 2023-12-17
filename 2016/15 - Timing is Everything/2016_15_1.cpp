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

int readInt(stringstream& ss) {
    char c;
    int x = 0;
    bool started = false;
    while(1) {
        ss >> c;
        if(isdigit(c)) {
            started = true;
            x = 10 * x + c - '0';
        } else if(started) {
            break;
        }
    }
    return x;
}

const int N = 11;
int len[N], init[N];
int n;

bool solve(int t) {
    rep(i, 1, n) {
        int pos = (init[i] + t + i) % len[i];
        if(pos) return false;
    }
    return true;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        ++n;
        stringstream ss(line);
        readInt(ss);
        len[n] = readInt(ss);
        readInt(ss);
        init[n] = readInt(ss);
    }
    int t = 0;
    while(1) {
        if(solve(t)) {
            cout << t << endl;
            return 0;
        }
        t++;
    }
    return 0;
}
