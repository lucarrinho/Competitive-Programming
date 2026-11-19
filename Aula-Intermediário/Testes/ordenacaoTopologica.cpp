#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> grau, ordem;

void kahn(int n){
    for (int v = 1; v <= n; v++){
        for (int to: adj[v])
            grau[to]++;
    }

    queue<int> fila;
    for (int v = 1; v <= n; v++){
        if (grau[v] == 0)
            fila.push(v);
    }

    while (!fila.empty()){
        int v = fila.front(); fila.pop();
        ordem.push_back(v);
        for (int to: adj[v]){
            grau[to]--;
            if (grau[to] == 0)
                fila.push(to);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n+1, vector<int>); grau.resize(n+1, 0);

    for (int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
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
