#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> vertices;

ll cross(pair<ll, ll> a, pair<ll, ll> b){
    return a.first * b.second - a.second * b.first;
}

ll area2(){
    ll resp = 0;
    int n = vertices.size();
    for (int i = 0; i < n-1; i++){
        resp += cross(vertices[i], vertices[i+1%n]);
    }
    return resp;
}

void solve() {
    int n; cin >> n;
    while (n--){
        ll x, y; cin >> x >> y;
        vertices.push_back({x, y});
    }

    ll resp = area2() / 2;
    cout << resp << "\n";
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
