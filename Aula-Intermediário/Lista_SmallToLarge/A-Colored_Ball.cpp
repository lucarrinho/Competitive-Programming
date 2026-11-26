#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<set<int>> box;

void solve() {
    int n, q; cin >> n >> q;
    box.resize(n+1, {});
    for (int i = 1; i <= n; i++){
        int c; cin >> c;
        box[i].insert(c);
    }

    while (q--){
        int a, b; cin >> a >> b;
        if (box[a].size() > box[b].size())
            swap(box[a], box[b]);
        box[b].merge(box[a]);
        box[a].clear();
        cout << box[b].size() << "\n";
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
