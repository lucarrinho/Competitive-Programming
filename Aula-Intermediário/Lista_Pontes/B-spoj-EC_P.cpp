#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int timer = 1;
vector<vector<int>> adj;
vector<pair<int, int>> bridges;
vector<int> tin, low;

void dfsBuild(int v, int pr){
    tin[v] = low[v] = timer++;

    for(int to: adj[v]) if(to != pr){
        if (tin[to] > 0){
            low[v] = min(low[v], tin[to]);
        } else {
            dfsBuild(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                if (v > to) bridges.push_back({to, v});
                else bridges.push_back({v, to});
            }
        }
    }
}

int c = 1;
void solve() {
    int n, m; cin >> n >> m;
    adj.assign(n+1, {});
    tin.assign(n+1, 0); low.assign(n+1, 0);
    bridges.assign(0, {});

    while (m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsBuild(1, 1);

    cout << "Caso #" << c++ << "\n";
    if (bridges.size() == 0) cout << "Sin bloqueos\n";
    else {
        cout << bridges.size() << "\n";
        sort(bridges.begin(), bridges.end());
        for (auto [a, b]: bridges)
            cout << a << " " << b << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
