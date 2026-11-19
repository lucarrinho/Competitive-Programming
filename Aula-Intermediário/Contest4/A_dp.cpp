#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, dp;

void dfs(int v, int pr = -1){
    for (int ch: adj[v]){
        dfs(ch, v);
        dp[v][0] += dp[ch][0];
        dp[v][1] += dp[ch][1];
    }
}

void solve() {
    int n; cin >> n;
    adj.assign(n+1, {});
    dp.assign(n+1, {0, 0});

    for (int i = 2; i <= n; i++){
        int a; cin >> a;
        adj[a].push_back(i);
    }
    string cor; cin >> cor;
    for (int i = 0; i < n; i++){
        if (cor[i] == 'W') dp[i+1][0] = 1;
        else dp[i+1][1] = 1;
    }

    dfs(1);
    int resp = 0;
    for (int i = 1; i <= n; i++){
        if (dp[i][0] == dp[i][1]) resp++;
    }
    cout << resp << endl;
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