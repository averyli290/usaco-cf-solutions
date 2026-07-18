/*
Problem link: https://codeforces.com/contest/1829/problem/E
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

const int MAXN = 1e6;
struct DSU {
    vector<int> parent;
    vector<int> size;
    vll val;

    DSU() {
        parent = vector<int>(MAXN);
        size = vector<int>(MAXN, 0);
        val = vll(MAXN, 0);
    }
    DSU(int n) {
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1, 0);
        val = vll(MAXN + 1, 0);
    }
    void make_set(int v, ll value) {
        parent[v] = v;
        size[v] = 1;
        val[v] = value;
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
            val[a] += val[b];
        }
    }
};


void solve() {
    int n, m; cin >> n >> m;
    vector<vll> a(n, vll(m, 0ll));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    ll ans = 0ll;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    function<ll(pii)> bfs = [&] (pii src) {
        queue<pii> dumb;
        dumb.push(src);
        ll cur = 0ll;
        vis[src.first][src.second] = true;
        while(!dumb.empty()) {
            auto [i, j] = dumb.front();
            // cout << i << " " << j <<endl;
            // cout << a[i][j] << endl;
            dumb.pop();
            cur += a[i][j];
            if (i > 0 && a[i - 1][j] != 0 && !vis[i - 1][j]) {
                dumb.push({i - 1, j});
                vis[i - 1][j] = true;
            }
            if (j > 0 && a[i][j - 1] != 0 && !vis[i][j - 1]) {
                dumb.push({i, j - 1});
                vis[i][j - 1] = true;
            }
            if (i < n - 1 && a[i + 1][j] != 0 && !vis[i + 1][j]) {
                dumb.push({i + 1, j});
                vis[i + 1][j] = true;
            }
            if (j < m - 1 && a[i][j + 1] != 0 && !vis[i][j + 1]) {
                dumb.push({i, j + 1});
                vis[i][j + 1] = true;
           }
        }
        return cur;
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (a[i][j] != 0 && !vis[i][j]) {
                ans = max(bfs({i, j}), ans);
                // cout << "HERE" << endl;
            }
        }
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
