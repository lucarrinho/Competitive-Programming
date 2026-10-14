#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

vector<vector<ll>> adj, dp;

ll dfs(int v, int pai, int cor){
    if (dp[v][cor] != -1) return dp[v][cor];
    dp[v][cor] = 1;

    for (auto ch: adj[v]){
        if (ch == pai) continue;
        if (cor){
            dp[v][cor] *= (dfs(ch, v, !cor))%MOD;
        } else {
            dp[v][cor] *= (dfs(ch, v, !cor)%MOD + dfs(ch, v, cor)%MOD)%MOD;
        }

        dp[v][cor] %= MOD;
    }
    return dp[v][cor];
}

void solve() {
    int n; cin >> n;
    dp.resize(n+1, vector<ll>(2, -1));
    adj.resize(n+1);
    n--;
    while(n--){
        ll x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    ll ans = (dfs(1, -1, 0) + dfs(1, -1, 1))%MOD;
    cout << ans << endl;
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
