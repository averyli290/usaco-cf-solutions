/*
Problem link: https://codeforces.com/contest/2060/problem/E
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;

const int MAXN = 1e5;

struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU() {
        parent = vector<int>(MAXN);
        size = vector<int>(MAXN, 0);
    }
    DSU(int n) {
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1, 0);
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    DSU f(n);
    DSU g(n);
    for(int i = 1; i <= n; i++) {
        f.make_set(i);
        g.make_set(i);
    }
    set<pii> adjf;
    for(int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        adjf.insert({u, v});
    }
    set<pii> adjg;
    for(int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        adjg.insert({u, v});
        g.union_sets(u, v);
    }
    int ans = 0;
    // remove edges first
    // check each edge in f, if vertices are same CC in g, then keep edge, otherwise remove

    for(auto &[u, v] : adjf) {
        if (g.find_set(u) != g.find_set(v)) ans++;
        else f.union_sets(u, v);
    }

    // add connectability
    for(auto &[u, v] : adjg) {
        if (g.find_set(u) == g.find_set(v) && f.find_set(u) != f.find_set(v)) {
            f.union_sets(u, v);
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
