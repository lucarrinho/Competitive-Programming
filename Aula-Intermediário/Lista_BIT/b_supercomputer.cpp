#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT{
    int n;
    vector<ll> v;

    BIT(int n_): n(n_), v(n+1){}

    void flip(int i){
        if (query(i) - query(i-1) == 1) add(i, -1);
        else add(i, 1);
    }
    void add(int i, ll val){
        for (; i <= n; i += i & (-i)){
            v[i] += val;
        }
    }

    int query(int i){
        ll resp = 0;
        for (; i > 0; i -= i & (-i)){
            resp += v[i];
        }
        return resp;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    BIT b(n);

    while (k--){
        char x; cin >> x;
        if (x == 'F'){
            int i; cin >> i;
            b.flip(i);
        }
        else if (x == 'C'){
            int l, r; cin >> l >> r;
            cout << (b.query(r) - b.query(l-1)) << endl;
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

