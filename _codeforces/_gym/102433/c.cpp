/*
Problem link:
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


void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1, vi{});
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<pii> q;
    q.push({1, 0});
    vector<bool> vis(n + 1, false);
    vi dist(n + 1, INT_MAX);
    dist[1] = 0;
    while(!q.empty()) {
        auto [cur, w] = q.front();
        q.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        if (cur == n) break;
        for(int neig : adj[cur]) {
            if (!vis[neig]) {
                if (dist[neig] > w + 1) {
                    dist[neig] = w + 1;
                    q.push({neig, w + 1});
                }
            }
        }
    }
    cout << dist[n] - 1 << endl;
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
