#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int max_num = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > max_num) max_num = a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans = max(ans, a[j] ^ a[i]);
        }
    }
    cout << ans << endl;
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