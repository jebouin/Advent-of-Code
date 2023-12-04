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

struct Node {
    bool isFile;
    int tot;
    string name;
    vector<Node*> ch;
    Node *par;

    Node(string name) {
        isFile = false;
        tot = 0;
        this->name = name;
        par = NULL;
    }

    bool hasChild(string name) {
        rall(c, ch) {
            if(c->name == name) {
                return true;
            }
        }
        return false;
    }

    void addDir(string name) {
        if(hasChild(name)) return;
        Node *d = new Node(name);
        d->par = this;
        ch.pb(d);
    }
    void addFile(string name, int x) {
        if(hasChild(name)) return;
        Node* node = new Node(name);
        node->isFile = true;
        node->tot = x;
        node->par = this;
        ch.pb(node);
        while(node->par != NULL) {
            node = node->par;
            node->tot += x;
        }
    }

    int solve() {
        if(isFile) return 0;
        int ans = tot <= 100'000 ? tot : 0;
        rall(c, ch) {
            ans += c->solve();
        }
        return ans;
    }
};



signed main() {
    freopen("input.txt", "r", stdin);
    Node root("/");
    Node *cur = &root;
    string w, cmd, par;
    while(cin >> w) {
        if(w == "$") {
            cin >> cmd;
            if(cmd == "ls") {
            } else if(cmd == "cd") {
                cin >> par;
                if(par == "/") {
                    cur = &root;
                } else if(par == "..") {
                    cur = cur->par;
                } else {
                    rall(d, cur->ch) {
                        if(d->name == par) {
                            cur = d;
                            break;
                        }
                    }
                }
            }
        } else if(isdigit(w[0])) {
            int si = atoi(w.c_str());
            string name;
            cin >> name;
            cur->addFile(name, si);
        } else if(w == "dir") {
            string name;
            cin >> name;
            cur->addDir(name);
        }
    }
    cout << root.solve() << endl;
    return 0;
}
