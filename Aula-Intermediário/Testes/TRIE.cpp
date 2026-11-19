#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
struct trie{
    trie() {}
    struct node{
        bool end;
        int ch[26];
        node() { memset(ch, -1, sizeof ch), end = false}
    };
    node nodo[N];
    int head = 0;
    void insert(){
        
    }

    void remove(){

    }

};

void solve() {

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
