/*
Problem link: https://codeforces.com/contest/1991/problem/E
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
if not bipartite, Alice wins
choose colors 1, 2 each turn

otherwise only use two colors to simplify
color bipartite graph with 1 or 2

each query simplifies to 1(3), 2
if 1's not filled (vertex x), color vertex x with 1
if 2's not filled (vertex x), color vertex x with 2

greedy fill 1/2, then assign 3 once all are filled

*/


void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1, vi{});
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n + 1, false);
    vi color(n + 1, -1);
    vi zv;
    vi ov;
    bool bipartite = true;
    function<void(int, int, int)> dfs = [&] (int cur, int par, int ctr) {
        color[cur] = ctr;
        vis[cur] = true;
        if (ctr == 0) zv.push_back(cur);
        else ov.push_back(cur);
        for(int neig : adj[cur]) {
            if (color[cur] == color[neig]) {
                bipartite = false;
                return;
            }
            if (!vis[neig]) dfs(neig, cur, (ctr + 1) % 2);
        }
    };
    dfs(1, -1, 0);

    if (bipartite) {
        int two = -1;
        int zctr = 0;
        int octr = 0;
        if (sz(zv) == 0) two = 1;
        if (sz(ov) == 0) two = 0;
        cout << "Bob" << endl;
        cout.flush();
        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            x--; y--;
            if (x > y) swap(x, y);
            if (x == 0 || y == 0) { // try to fill 0
                if (zctr < sz(zv)) {}
            }
        }
    } else {
        cout << "Alice" << endl;
        cout.flush();
        for(int i = 0; i < n; i++) {
            cout << "1 2" << endl;
            cout.flush();
            int x, y; cin >> x >> y;
        }
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
