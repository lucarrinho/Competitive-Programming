#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct bit {
    int n;
    vector<ll> a;

    bit(int n_): n(n_), a(n+1){}

    void add(int i, ll x){
        for (;i <= n; i += (i & (-i))){
            a[i] += x;
        }
    }

    void update(int k, ll u){
        ll dif = u - a[k];
        add(k, dif);
    }

    ll query(int i){
        ll resp = 0;
        for (;i > 0; i -= (i & (-i))){
            resp += a[i];
        }
        return resp;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    bit seq(n);

    ll x;
    for (int i = 1; i <= n; i++){
        cin >> x;
        seq.add(i, x);
    }

    while (q--){
        int op;
        cin >> op;
        if (op == 1){
            int k; ll u;
            cin >> k >> u;
            cin >> k >> u;
            seq.update(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            ll resp = seq.query(b) - seq.query(a-1);
            cout << resp << endl;
        }
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

