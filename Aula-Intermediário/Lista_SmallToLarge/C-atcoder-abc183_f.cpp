#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<set<int>> colors;
vector<int> cor, ans;

void dfs(int v, int pr){
    for (int ch: adj[v]){
        if (ch == pr) continue;
        dfs(ch, v);
        if (colors[ch].size() > colors[v].size())
            swap(colors[ch], colors[v]);
    }

    colors[v].insert(cor[v]);
    for (int ch: adj[v]){
        if (ch == pr) continue;
        for (int c: colors[ch])
            colors[v].insert(c);
        colors[ch].clear(); //opcional
    }
    ans[v] = colors[v].size();
}

void solve() {
    int n, q, c; cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> c;
        // c é a classe do i-ésimo estudante
    }

    while (q--){
        // querys
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
