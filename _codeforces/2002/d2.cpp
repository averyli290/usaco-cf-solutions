/*
Problem link: https://codeforces.com/contest/2002/problem/D2
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

https://www.youtube.com/watch?v=Q4HyYE_cEo8

following numbers cannot be ancestors of cur

我有神經病

think about shape of dfs
next number must be a child of cur or child of some ancestor of cur for dfs ordering
=> next number cannot be an ancestor (inductively shows above property)
=> parent of next must ancestor of current number
        (have to go up ancestors of cur including itself and offshoot from that path to get to next)
idk if this is sufficient feels tight enuff

tldr: next number must be adjacent to but not lie on ancestral path of current number

lca?

*/

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        // to search for node at height 2^(x + 1), search for = 2^x + 2^x
        // 2^i above v = up[v][i-1], 2^i again is up[up[v][i-1]][i-1]
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

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
    int q; cin >> n >> q;

    vi par(n, -1);
    vi p(n);
    adj.assign(n, vi{});
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
        par[i] = x;
    }

    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    preprocess(0);
    
    int goodge = 0;
    vi goodge_arr(n, 0);

    auto check = [&] (int idx) {
        // debug(idx);
        if (idx == 0 || idx >= n) return;     // check root separately
        if (goodge_arr[idx]) goodge--;
        goodge_arr[idx] = 0;
        // debug(p[idx]);
        // debug(p[idx - 1]);
        // debug(par[p[idx - 1]]);
        // debug(!is_ancestor(p[idx], p[idx - 1]));
        // debug(is_ancestor(par[p[idx - 1]], p[idx]));
        // debug(par[p[idx]]);
        if (!is_ancestor(p[idx], p[idx - 1]) && is_ancestor(par[p[idx]], p[idx - 1])) goodge_arr[idx] = 1;
        goodge += goodge_arr[idx];
        // debug(goodge_arr[idx]);
    };

    for(int i = 0; i < n; i++) {
        check(i);
        // debug(goodge_arr[i]);
    }


    while(q--) {
        int x, y; cin >> x >> y;
        x--; y--;
        if (x > y) swap(x, y);
        swap(p[x], p[y]);
        // cout << x <<  " " << y << endl;
        check(x);
        // debug(goodge);
        check(x + 1);
        // debug(goodge);
        check(y);
        // debug(goodge);
        check(y + 1);
        // debug(goodge);
        // debug(p[0]);
        if (goodge == n - 1 && p[0] == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
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
    
}
