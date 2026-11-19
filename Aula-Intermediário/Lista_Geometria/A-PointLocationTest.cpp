#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> vet(pair<ll, ll> a, pair<ll, ll> b){
    return {b.first - a.first, b.second - a.second};
}

ll cross(pair<ll, ll> u, pair<ll, ll> v){
    return u.first * v.second - u.second * v.first;
}

ll orient(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    return cross(vet(a, b), vet(b, c));
}

void solve() {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    pair<ll, ll> p1 = {x1, y1};
    pair<ll, ll> p2 = {x2, y2};
    pair<ll, ll> p3 = {x3, y3};
    ll r = orient(p1, p2, p3);
    if (r > 0)
        cout << "LEFT" << "\n";
    else if (r == 0)
        cout << "TOUCH" << "\n";
    else
        cout << "RIGHT" << "\n";
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
