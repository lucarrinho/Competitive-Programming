#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
const int N = 2e5, LOG = 20;

int adj[N][N-1];
int dep[N];
int p[N][20];

void dfs_build(int v, int pr) {
    //calcula ancestrais
    for (int i = 1; 1 < LOG; i++) {
        p[v][i] = p[p[v][i-1]][i-1];
        //dar um pulo tamanho 2^k é a mesma coisa de
        //dar dois pulos de tamanho 2^(k-1)
        //4 = 2 + 2
    }

    for (auto ch: adj[v]){
    if(ch == pr) continue;
    p[ch][0] = v;
    dep[ch] = dep[v] + 1;
    dfs_build(ch, v);
    }
}

int lca(int v, int u){
    if(dep[v] < dep[u]) swap(v, u);

    int dist = dep[v] - dep[u];
    
    for (int i = 0; i < LOG; i++){
        if(dist & (1 << i)) {
            u = p[u][i];
        }
    }

    if(v == u) return v;
    //se você igualar as alturas e eles terminaram no
    //mesmo vértice, então ele é o LCA

    for(int i = LOG - 1; i >= 0; i--){
        //se o ancestral 2^k é diferente então subimos para ele
        if(p[v][i] != p[u][i]) {
            v = p[v][i];
            u = p[u][i];
        }
    }

    return p[v][0];
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

