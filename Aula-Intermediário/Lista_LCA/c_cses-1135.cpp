#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int LOG = 20;

vector<int> dep;
vector<vector<int>> p, adj;
void dfs_build(int v, int pai){
    for (int i = 1; i < LOG; i++){
        p[v][i] = p[p[v][i-1]][i-1];
    }
    for (int ch: adj[v]){
        if(ch == pai) continue;
        p[ch][0] = v;
        dep[ch] = dep[v] + 1;
        dfs_build(ch, v);
    }
}

int lca(int u, int v){
    if (dep[v] < dep[u]) swap(u, v);
    int dist = dep[v] - dep[u];
    for (int i = 0; i < LOG; i++){
        if (dist & (1 << i)){
            v = p[v][i];
        }
    }
    if (u == v) return v;
    for (int i = LOG-1; i >= 0; i--){
        if (p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[v][0];
}

void solve() {
    int n, q; cin >> n >> q;
    dep.resize(n+1);
    p.resize(n+1, vector<int>(LOG));
    adj.resize(n+1);
    int a, b;
    for (int i = 1; i < n; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_build(1, 1);

    while (q--){
        cin >> a >> b;
        int comum = lca(a, b);
        int resp = dep[a] - dep[comum] + dep[b] - dep[comum];
        cout << resp << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

