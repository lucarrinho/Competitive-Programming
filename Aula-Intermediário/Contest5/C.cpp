#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> dist;

void dfsbuild(int v, int pr = 0){
    dist[v] = dist[pr] + 1;
    for (int ch: adj[v]){
        if (ch == pr) continue;
        dfsbuild(ch, v);
    }
}

int dfs_char(int v, int prof, string letras){
    if (dist[v] > prof) return 0;
    if (dist[v] == prof) return (int)letras[v-1];
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n+1); dist.resize(n+1);
    for (int i = 2; i <= n; i++){
        int p; cin >> p;
        adj[p].push_back(i);
    }
    dist[0] = 0; dfsbuild(1);

    string letras; cin >> letras;

    while (m--){
        int v, h; cin >> v >> h;
        int ans = dfs_char(v, h, letras);
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
