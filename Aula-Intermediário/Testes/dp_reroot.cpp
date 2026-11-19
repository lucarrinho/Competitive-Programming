#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[N];
int sub[N], ans[N];
ll sum = 0;

void dfs_build(int v, int pr){
    for (int ch: adj[v]){
        if(ch == pr) continue;

        dfs_build(ch, v);
        sub[v] += sub[ch];
        sum += sub[v];
    }
}

void dfs_reroot(int v, int pr){

}

void solve() {
    int n; cin >> n;

    for (int i = 1; i < n; i++){
        int v, u; cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs_build(1, -1);

    ans[1] = sum - sub[1];
    dfs_reroot(1, -1);

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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