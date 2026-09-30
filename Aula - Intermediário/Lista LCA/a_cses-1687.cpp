#include <bits/stdc++.h>
#include <utility>
using namespace std;
const int N = 2e5+1, LOG = 20;

int dep[N] = {0};
int p[N][LOG];
vector<vector<int>> adj(N);

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
    int resp = u;
    for (int i = 0; i < LOG; i++){
        if (dist & (1 << i)){
            resp = p[resp][i];
        }
    }
    if (u==v) return v;
    for (int i = LOG-1; i >= 0; i--){
        if (p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[v][0];
}

void solve() {
    int n, q, x, k;
    cin >> n >> q;
    for (int i = 2; i <= n; i++){
        cin >> x;
        adj[x].push_back(i);
    }
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
