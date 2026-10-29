#include <bits/stdc++.h>
using namespace std;

int timer;
vector<vector<int>> adj;
vector<int> tin, tout;

struct bit{
    int n; vector<int> a;
    bit(int n_): n(n_), a((2*n)){}

    void add(int i, int x){
        for (; i < (2*n); i += (i & (-i))){
            a[i] += x;
        }
    }

    int query(int i, int j){
        int somai = 0, somaj = 0;

        for (; i > 0; i -= (i & (-i)))
            somai += a[i];

        for (; j > 0; j -= (j & (-j)))
            somaj += a[j];

        return somaj - somai;
    }
};

void dfs_build(string s, bit &tour, int v, int pr = -1){
    timer++;
    tin[v] = timer;
    if (s[v-1] == 'W') tour.add(timer, 1);
    else tour.add(timer, -1);

    for (int ch: adj[v]){
        if (ch == pr) continue;
        dfs_build(s, tour, ch, v);
    }

    tout[v] = timer;
}

void solve() {
    int n; cin >> n;
    adj.assign(n+1, {});
    tin.assign(n+1, 0); tout.assign(n+1, 0);
    bit tour(n);

    int a;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        adj[a].push_back(i);
    }

    string s; cin >> s; timer = 0;
    dfs_build(s, tour, 1);

    int resp = 0;
    for (int i = 1; i <= n; i++){
        if (tour.query(tin[i]-1, tout[i]) == 0) resp++;
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
