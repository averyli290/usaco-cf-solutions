/*
Problem link: https://codeforces.com/contest/1986/problem/B
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
store subtree sizes
find if point is reachable by only one path
(implies removing the edge which gets to it will create two components)

try using timer
try subtracting max of product of two from total (n(n-1))/2

4 3
2 3
4 1
2 1

2-3
|
1-4

5 5
1 2
1 3
3 4
4 5
5 3


1-2
|
3
| \
4-5

5 5
1 2
1 3
2 3
2 4
3 5

1-2-4
|/
3
|
5

*/

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low, subtree;
int timer;
ll maxval;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    subtree[v] += 1;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            subtree[v] += subtree[to];
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                maxval = max(maxval, (((ll) (n - subtree[to])) * (subtree[to])));
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    subtree.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void solve() {
    int m; cin >> n >> m;
    maxval = 0LL;
    adj.clear();
    adj.assign(n, vi{});
    for(int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    find_bridges();
    cout << ((ll) n) * ((ll) (n - 1)) / 2 - maxval << endl;
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
