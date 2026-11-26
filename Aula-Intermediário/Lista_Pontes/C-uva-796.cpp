#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int timer = 0;
vector<vector<int>> adj;
vector<pair<int, int>> bridges;
vector<int> tin, low;

void dfsBuild(int v, int pr){
    tin[v] = low[v] = timer++;

    for(int to: adj[v]) if(to != pr){
        if (tin[to] != -1){
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

void solve(int n) {
    adj.assign(n, {}); timer = 0;
    tin.assign(n, -1); low.assign(n, -1);
    bridges.clear();

    char c;
    for (int i = 0; i < n; i++){
        int u, v; cin >> u;
        cin >> c;
        int m; cin >> m;
        cin >> c;
        while (m--){
            cin >> v;
            adj[u].push_back(v);
        }
    }

    for (int i = 0; i < n; i++) if (tin[i] == -1){
        dfsBuild(i, i);
    }

    cout << bridges.size() << " critical links\n";
    sort(all(bridges));
    for (auto [a, b]: bridges)
        cout << a << " " << b << "\n";
}

int main() {
    fastio;
    int n;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}
