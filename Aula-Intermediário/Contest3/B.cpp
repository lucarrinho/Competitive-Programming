#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dfs(vector<vector<int>> adj, int dep[], int v, int pai, int d = 0){
    dep[v] = d;
    int a = dep[v];
    for (auto ch: adj[v]){
        if (ch == pai) continue;
        a = max(a, dfs(adj, dep, ch, v, dep[v]+1));
    }
    return a;
}

int maxDepth(vector<vector<int>> adj, int len){
    int depth[len+1];
    dfs(adj, depth, 1, -1);
    int idx = 1;
    for (int i = 2; i <= len; i++){
        if (depth[i] > depth[idx]) idx = i;
    }
    return dfs(adj, depth, idx, -1, 0);
}

void solve() {
    int n; cin >> n;
    int max_comp = 0;
    while (n--){
        int ni, a, b; cin >> ni;
        vector<vector<int>> adj(ni+1);
        for (int i = 1; i < ni; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        max_comp += maxDepth(adj, ni);
    }
    cout << max_comp << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
