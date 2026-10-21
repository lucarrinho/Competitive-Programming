#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct bit {
    int n;
    vector<ll> v;

    bit(int n_): n(n_), v(n+1){}

    void build(vector<int> arr){
        for (int i = 1; i <= n; i++){
            add(i, arr[i]);
        }
    }

    void add(int i, ll x){
        for (;i <= n; i += (i & (-i))){
            v[i] += x;
        }
    }

    ll query(int i){
        ll resp = 0;
        for (;i > 0; i -= (i & (-i))){
            resp += v[i];
        }
        return resp;
    }
};

void solve() {
    int n, q, x, y, z;
    cin >> n >> q;
    bit v(n);

    vector<int> array(n+1);
    for (int i = 1; i <= n; i++){
        cin >> array[i];
    }
    v.build(array);

    while (q--){
        cin >> x >> y >> z;
        if (x == 1){
            int val = z - array[y];
            v.add(y, val);
            array[y] += val;
        } else {
            ll resp = v.query(z) - v.query(y-1);
            cout << resp << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}