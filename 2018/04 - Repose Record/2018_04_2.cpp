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

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    vector<string> lines;
    while(getline(cin, line)) {
        lines.pb(line);
    }
    sort(rng(lines));
    int curId, last = 0;
    map<int, vector<int> > times;
    rall(line, lines) {
        string day, time;
        stringstream ss(line);
        ss >> day >> time;
        int mi = 0;
        if(time[0] == '0' && time[1] == '0') {
            mi = (time[3] - '0') * 10 + time[4] - '0';
        }
        string word;
        ss >> word;
        if(word == "Guard") {
            string idstr;
            ss >> idstr;
            curId = atoi(idstr.substr(1).c_str());
            if(times.find(curId) == times.end()) {
                times[curId] = vector<int>(60);
            }
        } else if(word == "wakes") {
            rep(t, last, mi) {
                times[curId][t]++;
            }
        } else if(word == "falls") {
            last = mi;
        }
    }
    int maxi = 0, bestId = 0, bestMinute = 0;
    rall(p, times) {
        rep(m, 0, 59) {
            int cnt = p.se[m];
            if(cnt > maxi) {
                maxi = cnt;
                bestId = p.fi;
                bestMinute = m;
            }
        }
    }
    int ans = bestId * bestMinute;
    cout << ans << endl;
    return 0;
}
