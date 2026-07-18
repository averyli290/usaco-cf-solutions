/*
Problem link: https://cses.fi/problemset/task/1688/
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
precompute powers of 2 jumps upwards for each node

keep track of log n powers of 2 above for each node
to update, for each node, take parent node and take child of each previous node to get
adjusted distance (adds 1 to each depth). if the 

7 3
1 1 3 3 5 5
4 1
4 2
4 3

1
|\
2 3
  |\
  4 5
    |\
    6 7

5
3
4
6
2
3
-1
1
3
1

binary search for depth of boss
store depths

binary lifting

*/

void solve() {
    int n, q; cin >> n >> q;

    vector<vi> adj(n + 1, vi{});
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
    }
    
    int jarjar = 1; // log n
    int temp = 1;
    set<int> powers;
    while(temp <= n) {
        powers.insert(temp);
        temp <<= 1;
        jarjar++;
    }
    jarjar--;

    vector<vi> jumps(n + 1, vi(jarjar, -1));

    vi tin(n + 1, -1);
    vi tout(n + 1, -1);
    function<void(int, int, int, vi&, int&)> dfs = [&] (int cur, int par, int depth, vi& path, int& t) {
        tin[cur] = t;
        t++;
        auto ptr = powers.find(depth);
        // debug(1);
        // debug(cur);
        if (ptr != powers.end()) {
            int ctr = 0;
            int val = *ptr;
            while (val > 1) {
                ctr++;
                val >>= 1;
            }
            // debug(cur);
            // debug(ctr);
            jumps[cur][ctr] = 1;
        }
        // debug(par);
        if (par != -1) {
            // cout << "processing: ";
            // cout << cur << " " << par << endl;
            jumps[cur][0] = par;
            for(int i = 1; i < jarjar; i++) {
                if (jumps[par][i] != -1) {
                // cout << i << " " << jumps[par][i] << endl;
                    jumps[cur][i] = path[jumps[par][i]];
                // debug(jumps[cur][i]);
                }
            }
        }

        for(int neig : adj[cur]) {
            // cout << cur << " " << neig << endl;
            path[cur] = neig;
            // path[neig] = cur;
            dfs(neig, cur, depth + 1, path, t);
            // path[neig] = -1;
        }
        path[cur] = -1; // reset cur child
        tout[cur] = t;
        t++;
    };

    function<bool(int, int)> is_ancestor = [&] (int u, int v) {
        if (u == -1 || v == -1) return true;
        return tin[u] <= tin[v] && tout[u] >= tout[v];      // check ancestor based on dfs times
    };

    function<int(int, int)> lca = [&] (int u, int v) {
        if (is_ancestor(u, v)) {
            return u;
        } else if (is_ancestor(v, u)) {
            return v;
        } else {
            // jump as far as possible each time without becoming ancestor
            // only have to jump a each power of 2 at most once
            for(int i = jarjar - 1; i >= 0; i--){
                if (!is_ancestor(jumps[u][i], v)) {
                    u = jumps[u][i];
                }
            }
            // now u is highest ancestor of original u which is not an ancestor of v
            // return direct parent this new u, must be an ancestor of v
            return jumps[u][0];
        }
    };

    vi path(n + 1, -1);
    int t = 0;
    dfs(1, -1, 0, path, t);

    while(q--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << endl;
    }

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
