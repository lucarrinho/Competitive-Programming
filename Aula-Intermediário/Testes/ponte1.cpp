#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int timer = 0;
vector<vector<int>> adj;
vector<int> tin, low, is_bridge;

void dfsBuild(int v, int pr = -1){
    timer++;
    tin[v] = low[v] = timer;
    tempo++;
    for(int to: adj[v]){
        if (to == pr) continue;
        if (tin[to]){
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                is_bridge[to] = 1;
            }
        }
    }
}

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
