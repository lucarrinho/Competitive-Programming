#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int tempo = 0;
vector<vector<int>> adj;
vector<int> tin, tout, tour, values;

struct bit {
    int n; vector<ll> a;

    bit(int n_): n(n_), a((2*n)-1){}

    void build(){
    }

    void add(int i, ll x){
        for (; i <= n; i+= (i & (-1))){
            a[i] += x;
        }
    }

    void update(int i, ll v){
        ll atual = query(i);
        add(i, -atual); add(i, v);
    }

    ll query(int i){
        ll resp = 0;
        for (; i > 0; i -= (i & (-1)))
            resp += a[i];
        return resp;
    }
};

void dfsBuild(int v, int pr){
    tin[v] = tempo;
    tour[tempo] = values[v];
    tempo++;

    for (auto ch: adj[v]){
        if (ch == pr) continue;
        dfsBuild(ch, v);
    }

    tout[v] = tempo;
    tour[tempo] = 0;
    tempo++;
}

void solve() {
    int n, q; cin >> n >> q;
    values.resize(n+1);
    adj.resize(n+1, vector<int>);
    tin.resize(n+1); tout.resize(n+1);
    tour.resize(2 * n - 1);

    for (int i = 1; i <= n; i++)
        cin >> values[i];

    for (int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsBuild(1, -1);
    bit b(n);

    while (q--){
        int opt, s, x; cin >> opt;
        if (opt == 1){
            cin >> s >> x;
            b.update(s, x);
        }
        if (opt == 2){
            cin >> s;
            ll resp = b.query(tout[s]) - b.query(tin[s]-1);
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
