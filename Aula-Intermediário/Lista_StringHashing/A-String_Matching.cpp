#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M1 = 1e9+7, M2 = 1e9+9;
const int B;

vector<ll> h1, p1, h2, p2;

void construir(string s, vector<ll>& h, vector<ll>& p, ll M){
    int n = s.size();
    for (int i = 0; i < n; i++){
        h[i+1] = (h[i] * B + (int)s[i]) % M;
        p[i+1] = p[i] * B % M;
    }
}

ll hash_trecho(ll H, ll P, ll l, ll r, ll M){
    return (H[r] - H[l] * P[r-l]) % M;
}
ll hash_padrao(string s, ll M){
    // Como?????????????
}

void solve() {
    string s, padrao; cin >> s >> padrao;
    int n = s.size();
    h1.resize(n+1); h2.resize(n+1);
    p1.resize(n+1, 1); p2.resize(n+1, 1);

    construir(s, h1, p1, M1);
    construir(s, h2, p2, M2);

    ll hash_pad1 = hash_padrao(padrao, M1);
    ll hash_pad2 = hash_padrao(padrao, M2);

    int k = padrao.size(); int ans = 0;
    for (int i = 0; i < n-k; i++){
        // pegar hashs no intervalo [i, i+k-1]
        // comparar ambos hashs com hash do padrao
        // se igual: ans += 1;
    }
    cout << ans << endl;
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
