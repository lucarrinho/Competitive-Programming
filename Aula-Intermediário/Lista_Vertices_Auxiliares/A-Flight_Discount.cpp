#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll PESO_MAX = 1e18;

vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;

void dijkstra(){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> fila;
    fila.push({0, 1});
    dist[1] = 0;

    while (!fila.empty()){
        auto [peso, v] = fila.top();
        fila.pop();
        if (peso > dist[v]) continue;
        for (auto [ch, c]: adj[v]){
            if (peso + c < dist[ch]){
                dist[ch] = peso + c;
                fila.push({dist[ch], ch});
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(2*n + 1); dist.resize(2*n + 1, PESO_MAX+1);
    while (m--){
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[a+n].push_back({b+n, c});
        adj[a].push_back({b+n, c/2});
    }

    dijkstra();
    cout << dist[2*n] << endl;
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
