#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<set<int>> colors;
vector<int> cor, ans;

void dfs(int u, int pai){
    for (int ch: adj[u]){
        if (ch == pai) continue;
        dfs(ch, u);
        if (colors[ch].size() > colors[u].size())
            swap(colors[ch], colors[u]);
    }

    colors[u].insert(u);
    for (int ch: adj[u]){
        if (ch == pai) continue;
        for (int c: colors[ch])
            colors[u].insert(c);
        colors[ch].clear(); //opcional
    }
    ans[u] = colors[u].size();
}

void solve() {
    int n, c; cin >> n;
    adj.resize(n+1); colors.resize(n+1);
    cor.resize(n+1); ans.resize(n+1);

    for (int i = 1; i <= n; i++){
        cin >> c;
        cor[i] = c;
    }
    for (int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    
    cout << ans[1];
    for (int i = 2; i <= n; i++)
        cout << " " << ans[i];
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
