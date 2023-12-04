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

typedef map<pair<int, int>, int> Grid;

void readWire(Grid& grid, Grid& wire, int mask) {
    int x = 0, y = 0, len = 0;
    string line, s;
    getline(cin, line);
    stringstream ss(line);
    int opPos = 0;
    while(opPos < sz(line)) {
        int commaPos = line.find(',', opPos);
        if(commaPos == (int)string::npos) {
            commaPos = sz(line);
        }
        string s = line.substr(opPos, commaPos - opPos);
        opPos = commaPos + 1;
        char dir = s[0];
        int dist = stoi(s.substr(1));
        rep(j, 1, dist) {
            if(dir == 'L') {
                x--;
            } else if(dir == 'R') {
                x++;
            } else if(dir == 'U') {
                y--;
            } else if(dir == 'D') {
                y++;
            }
            grid[make_pair(x, y)] |= mask;
            wire[make_pair(x, y)] = ++len;
        }
    }
}

Grid grid, wire1, wire2;

signed main() {
    freopen("input.txt", "r", stdin);
    readWire(grid, wire1, 1);
    readWire(grid, wire2, 2);
    int ans = 1'000'000;
    rall(p, grid) {
        if(p.se != 3) continue;
        int sum = wire1[p.fi] + wire2[p.fi];
        if(sum < ans) {
            ans = sum;
        }
    }
    cout << ans << endl;
    return 0;
}
