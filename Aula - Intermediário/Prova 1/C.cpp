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
        if (ch == pai) continue;
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
        if (p[v][i] != p[u][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[v][0];
}

void solve(){
    vector<pair<int, int>> arestas, caminhos;
    int n; cin >> n;
    dep.resize(n+1);
    p.resize(n+1, vector<int>(LOG));
    adj.resize(n+1); n--;

    while(n--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        pair p{a, b};
        arestas[i].push_back(p);
    }
    int m, u, v; cin >> m;
    while(m--){
        cin >> u >> v;
        pair p{u, v};
        caminhos.push_back(p);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    
    while (t--){
        solve();
    }
}
