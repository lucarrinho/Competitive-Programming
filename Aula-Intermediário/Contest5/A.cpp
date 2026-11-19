#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX_COST = 2e18;

vector<vector<pair<int, int>>> adj;
vector<ll> dist;

void dijkstra(int v){
    priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> fila;
    fila.push({0, v});

    while (!fila.empty()){
        auto [d, v] = fila.top();
        fila.pop();
        if (d > dist[v]) continue;
        for (auto [to, c]: adj[v]){
            if (d + c < dist[to]){
                dist[to] = d + c;
                fila.push({dist[to], to});
            }
        }
    }
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    adj.resize((k+1)*n + 1); dist.resize((k+1)*n + 1, MAX_COST);
    while (m--){
        int i, j, f, w;
        cin >> i >> j >> f >> w;
        adj[i].push_back({j, f}); adj[j].push_back({i, f});

        for (int x = 1; x <= k; x++) {
            if (w != -1) {
                adj[i].push_back({j+n, w}); adj[j].push_back({i+n, w});
            }
            i += n; j += n;
            adj[i].push_back({j, f}); adj[j].push_back({i, f});
        }
    }
    dijkstra(1);

    ll ans = dist[n]; int t = dist.size();
    for (int i = 2*n; i < t; i += n){
        ans = min(ans, dist[i]);
    }
    cout << ans << "\n";
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
