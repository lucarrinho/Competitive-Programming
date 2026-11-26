#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int timer = 1;
vector<vector<int>> adj;
vector<pair<int, int>> bridges;
vector<int> tin, low, sub;
ll ans;

void dfsBuild(int v, int pr, int n){
    tin[v] = low[v] = timer++;
    sub[v] = 1;
    for (int to: adj[v]) if (to != pr){
        if (tin[to]){
            low[v] = min(low[v], tin[to]);
        } else {
            dfsBuild(to, v, n);
            sub[v] += sub[to];
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                ll s = sub[to];
                bridges.push_back({v, to});
                ans = min(ans, (s*(s-1)/2) + ((n-s)*(n-s-1)/2));
            }
        }
    }

}

void solve() {
    int n, m; cin >> n >> m;
    adj.assign(n+1, {}); timer = 0;
    tin.assign(n+1, 0); low.assign(n+1, 0);
    bridges.clear(); sub.assign(n+1, 0);

    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = (ll)n*(n-1)/2;
    dfsBuild(1, 1, n);
    cout << ans << "\n";
}

int main() {
    fastio;
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
