#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<ll> nums;

struct SegTree {
    vector<ll> seg;
    void init(){
        seg.resize(4*n);
        build(1, n, 1);
    }

    void build(int l, int r, int node){
        if (l == r) {
            seg[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node*2);
        build(mid+1, r, node*2+1);

        seg[node] = seg[node*2] + seg[node*2+1];
    }

    void update(int l, int r, ll val, int index, int node){
        if (l == r){
            seg[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if (index <= mid) update(l, mid, val, index, node*2);
        else update(mid+1, r, val, index, node*2+1);

        seg[node] = seg[node*2] + seg[node*2+1];
    }

    ll query(int l, int r, int s, int e, int node){
        if (l > e || r < s) return 0;
        if (s <= l && r <= e) return seg[node];
        int mid = (l+r)/2;
        return query(l, mid, s, e, node*2) + query(mid+1, r, s, e, node*2+1);
    }
};

void solve() {
    int q; cin >> n >> q;
    nums.resize(n+1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    SegTree sg; sg.init();

    while (q--){
        int x; cin >> x;
        if (x == 1){
            int k, u; cin >> k >> u;
            sg.update(1, n, u, k, 1);
        } else {
            int a, b; cin >> a >> b;
            cout << sg.query(1, n, a, b, 1) << endl;
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
