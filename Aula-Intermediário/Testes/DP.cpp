#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998572230;


void solve() {
    int n, k; cin >> n >> k;
    vector<ll> dp(n+1), pref(n+1);
    
    dp[1] = 1; pref[1] = 1;
    for (int i = 2; i <= n; i++){
        if (i - k > 0) dp[i] = pref[i-1] - pref[i-k-1];

        else dp[i] = pref[i-1];
        
        dp[i] %= MOD;
        pref[i] = dp[i] + pref[i-1];
    }
    cout << dp[n] << endl;
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
