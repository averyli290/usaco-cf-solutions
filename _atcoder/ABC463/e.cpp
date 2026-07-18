/*
Problem link: https://atcoder.jp/contests/abc463/tasks/abc463_e
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
    int n; cin >> n;
    int m; cin >> m;
    ll y; cin >> y;
    vector<vector<pii>> adj(n + 2, vector<pii>{});
    for(int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int i = 0; i < n; i++) {
        ll w; cin >> w;
        adj[i].push_back({n, w});
        adj[n + 1].push_back({i, w});
    }
    adj[n].push_back({n + 1, y});

    vector<bool> vis(n + 2, false);
    vector<ll> ans(n + 2, LLONG_MAX);
    priority_queue<pair<ll, int>> pq;
    pq.push({0ll, 0});
    while (!pq.empty()) {
        auto [dist ,cur] = pq.top();
        pq.pop();
        dist = -dist;
        if (vis[cur]) continue;
        vis[cur] = true;
        ans[cur] = dist;
        // debug(cur);
        // debug(dist);

        for(auto [neig, weight] : adj[cur]) {
            if (dist + weight < ans[neig]) {
                ans[neig] = dist + weight;
                if (cur == 0) {
                    // debug(neig);
                    // debug(weight);
                    // debug(ans[neig]);
                }
                if(!vis[neig]) pq.push({-(dist + weight), neig});
            }
        }
    }
    for(int i = 1; i< n; i++) {
        cout << ans[i] << " ";
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
