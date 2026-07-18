/*
Problem link: https://cses.fi/problemset/task/1687/
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

    vector<vi> jumps(n + 1, vi(jarjar, -1));

    function<void(int, int, int, vi&)> dfs = [&] (int cur, int par, int depth, vi& path) {
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
            dfs(neig, cur, depth + 1, path);
            // path[neig] = -1;
        }
        path[cur] = -1; // reset cur child
    };

    vi path(n + 1, -1);
    dfs(1, -1, 0, path);

    // for(int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for(int v : jumps[i]) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    while(q--) {
        int x, k; cin >> x >> k;
        while (k > 0 && x != -1) {
            int idx = 0;
            int cur = 1;
            while(cur <= k) {
                cur <<= 1;
                idx++;
            }
            cur >>= 1;
            k -= cur;
            idx--;
            x = jumps[x][idx];
            // if (jumps[x][idx] == -1) {
            //     cout << -1 << endl;
            //     done = true;
            // } else {
            //     x = jumps[]
            // }
        }
        cout << x << endl;
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
