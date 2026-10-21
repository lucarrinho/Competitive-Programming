#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string w; cin >> w;
    string ans = "";
    int l = w.length();
    for (int i = 0; i < l-2; i++){
        ans += w[i];
    }
    ans += 'i';
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
