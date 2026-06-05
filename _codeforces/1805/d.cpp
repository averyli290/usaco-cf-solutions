/*
Problem link: https://codeforces.com/contest/1805/problem/D
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
consider the diameter of the tree and what vertices the endpoints can be connected
to for a given k

greedy: for each node, find distance to furthest vertex
once k is greater than that distance, then that node will be in its own connected component
otherwise, the node will be connected to one of the tree's diameter endpoints, and therefore
will be connected to the other vertices whose greatest distance has not been exceeded

tldr: for each vertex, if len to furthest vertex from it has not been exceeded, it is in a
connected component which was existing earlier
*/


void dfs3(int cur, int par, vector<vi>& adj, vi& down) {
    for (int neig : adj[cur]) {
        if (neig == par) continue;

        dfs3(neig, cur, adj, down);
        down[cur] = max(down[cur], down[neig] + 1);
    }
}

void dfs4(int cur, int par, vector<vi>& adj, vi& down, vi& up) {
    int mx1 = -1;
    int mx2 = -1;
    for (int neig : adj[cur]) {
        if (neig == par) continue;
        int val = down[neig] + 1;
        if (val > mx1) {
            mx2 = mx1;
            mx1 = val;
        } else if (val > mx2) {
            mx2 = val;
        }
    }
    for (int neig : adj[cur]) {
        if (neig == par) continue;
        int use = mx1;
        if (down[neig] + 1 == mx1) use = mx2;
        up[neig] = max(up[cur], use) + 1;
        dfs4(neig, cur, adj, down, up);
    }
}

void solve() {
    int n; cin >> n;
    vector<vi> adj(n, vi{});

    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi down(n + 1, 0);
    vi up(n + 1, 0);
    dfs3(0, -1, adj, down);
    dfs4(0, -1, adj, down, up);
    int mval = 0;
    for(int i = 0; i < n; i++) {
        mval = max(mval, down[i]);
        mval = max(mval, up[i]);
    }
    vi inv(n + 1, 0);
    for(int i = 0; i < n; i++) inv[max(down[i], up[i])]++;
    int cur = 1;
    for(int i = 1; i <= n; i++) {
        cout << min(cur, n) << " ";
        cur += inv[i];
    }
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