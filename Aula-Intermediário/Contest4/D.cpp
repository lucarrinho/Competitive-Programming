#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> represas;

void solve() {
    int n; cin >> n;
    adj.assign(n+1, {});
    for (int i = 2; i <= n; i++){
        int a; cin >> a;
        adj[a].push_back(i);
    }
    int m; cin >> m;
    represas.assign(m, {});
    for (int i = 0; i < m; i++){
        cin >> represas[i];
    }

    sort(represas.begin(), represas.end());
    cout << m-1;
    for (int i = 1; i < m; i++)
        cout << " " << represas[i];
    cout << endl;
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