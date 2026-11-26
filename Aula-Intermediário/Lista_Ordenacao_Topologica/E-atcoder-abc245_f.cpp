#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7, INF = 1e18;

vector<vector<pair<ll, ll>>> adj;
vector<ll> grau, ordem, dist;

void dijkstra(){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> fila;
    dist[1] = 0;
    fila.push({0, 1});
    while (!fila.empty()){
        auto [d, v] = fila.top(); fila.pop();
        if (d > dist[v]) continue;
        for (auto [ch, c]: adj[v]){
            ll nova = dist[v] + c;
            if (nova < dist[ch]){
                dist[ch] = nova;
                fila.push({dist[ch], ch});
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n+1); grau.resize(n+1, 0);
    dist.resize(n+1, INF);
    for (int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkstra();
    vector<vector<pair<ll, ll>>> temp(n+1);
    for (ll v = 1; v <= n; v++){
        for (auto [ch, c]: adj[v]) if (dist[ch] == dist[v]+c) {
            temp[v].push_back({ch, c});
        }
    }
    adj = temp;

    for (ll v = 1; v <= (ll)n; v++){
        for (auto [to, c]: adj[v])
            grau[to]++;
    }

    priority_queue<ll, vector<ll>, greater<ll>> fila;
    for (ll v = 1; v <= n; v++){
        if (grau[v] == 0)
            fila.push(v);
    }

    while (!fila.empty()){
        ll v = fila.top(); fila.pop();
        ordem.push_back(v);
        for (auto [to, c]: adj[v]){
            grau[to]--;
            if (grau[to] == 0)
                fila.push(to);
        }
    }

    vector<ll> ways(n+1, 0), menor(n+1, INF), maior(n+1, 0);
    ways[1] = 1; menor[1] = 0;
    for (ll v: ordem){
        for (auto [to, c]: adj[v]){
            ways[to] = (ways[to] + ways[v]) % MOD;
            menor[to] = min(menor[to], menor[v]+1);
            maior[to] = max(maior[to], maior[v]+1);
        }
    }

    cout << dist[n] << " ";
    cout << ways[n] << " ";
    cout << menor[n] << " ";
    cout << maior[n] << "\n";
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