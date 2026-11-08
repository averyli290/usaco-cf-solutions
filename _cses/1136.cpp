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

vi ans;
vector<int> top;
vector<int> bot;
int dfs2(int cur, int par) {
    int val = 0;
    for(int neig : adj[cur]) {
        if (neig != par) {
            val += dfs2(neig, cur);
        }
    }
    val += bot[cur];
    val -= top[cur];
    ans[cur] = val;
    val -= top[cur];
    return val;
}

void solve() {
    int m; cin >> n >> m;
    adj.assign(n, vi{});
    ans.assign(n, 0);
    bot.assign(n, 0);
    top.assign(n, 0);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    preprocess(0);

    while(m--) {
        int a,b; cin >> a >> b;
        a--; b--;
        bot[a]++;
        bot[b]++;
        top[lca(a,b)]++;
    }
    dfs2(0, -1);
    for(int i = 0 ; i< n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
