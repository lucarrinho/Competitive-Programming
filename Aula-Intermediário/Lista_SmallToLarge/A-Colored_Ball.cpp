#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int>

void solve() {

    for (int i = 0; i < 1; i++){
        int a, b; cin >> a >> b;
        if (caixa[a].size() > caixa[b].size()){
            aux = caixa[a];
            caixa[a] = caixa[b];
            caixa[b] = aux;
        }
    }
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
