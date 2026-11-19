#include <bits/stdc++.h>
#include <vector>
#include <utility>
using namespace std;
const int N = 2e5+1, LOG = 20;

vector<int> dep;
vector<vector<int>> adj, p;

void dfs_build(int v, int pai){
    for(int i = 1; i < LOG; i++){
        p[v][i] = p[p[v][i-1]][i-1];
    }

    for (int ch: adj[v]){
        if (ch == pai) continue;
        p[ch][0] = v;
        dep[ch] = dep[v] + 1;
        dfs_build(ch, v);
    }
}

int findBoss(int u, int dist){
    if (dist > dep[u]) return -1;
    int resp = u;
    for (int i = 0; i < LOG; i++){
        if (dist & (1 << i)){
            resp = p[resp][i];
        }
    }
    return resp;
}

void solve() {
    int n, q, x, k;
    cin >> n >> q;
    
    dep.resize(n+1);
    adj.resize(n+1);
    p.resize(n+1, vector<int>(20));

    for (int i = 2; i <= n; i++){
        cin >> x;
        adj[x].push_back(i);
    }
    dep[1] = 0;
    dfs_build(1, 1);

    while (q--) {
        cin >> x >> k;
        cout << findBoss(x, k) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> q;

    while (t--) {
        solve();
    }

    return 0;
}