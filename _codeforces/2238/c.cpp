/*
Problem link: https://codeforces.com/contest/2238/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*
https://cp-algorithms.com/graph/lca_binary_lifting.html
*/

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<vector<int>> lvl;

void dfs(int v, int p, int d=0)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        // to search for node at height 2^(x + 1), search for = 2^x + 2^x
        // 2^i above v = up[v][i-1], 2^i again is up[up[v][i-1]][i-1]
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, d + 1);
    }

    lvl[d].push_back(v);
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}


void solve() {
    cin >> n;
    adj.assign(n, vi{});
    lvl.assign(n, vi{});
    for(int i = 1; i < n; i++) {
        int x; cin >> x; x--;
        adj[x].push_back(i);
    }

    preprocess(0);

    int ans = n;
    for(int i = 0; i < n; i++) {
        set<int> s;
        for(int j = 1; j < sz(lvl[i]); j++) {
            s.insert(lca(lvl[i][j - 1], lvl[i][j]));
        }
        ans += sz(s);
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
