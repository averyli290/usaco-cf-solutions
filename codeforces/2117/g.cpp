/*
Problem link: https://codeforces.com/contest/2117/problem/G
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

/*
if given current edge is minimum edge used in answer, greedily choose
path to 1 from edge and path to n from edge, ans is max edge along those
paths + current edge weight
max edge from given vertex to 1 can be calced used modified dijkstras,
same with vertex to n
don't need arbitrary i to j max edge, just use 1 and n as source to make faster
*/


vector<vii> adj;

// all subpaths of a minimal path are optimal
vi cost(int src) {
    int n = adj.size();
    priority_queue<pii> pq; // {weight, node} pair
    vector<bool> visited(n + 1, false);
    vi d(n + 1, INT_MAX);
    d[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [dist, cur_node] = pq.top(); pq.pop();
        if (visited[cur_node]) continue;
        dist = -dist;
        d[cur_node] = dist;
        visited[cur_node] = true;
        for (auto [neig, w] : adj[cur_node]) {
            if (visited[neig]) continue;
            if (max(w, d[cur_node]) < d[neig]) {    // check if need to update, if so, update and push to queue
                d[neig] = max(w, d[cur_node]);
                pq.push(pii{-d[neig], neig});
            }
        }
    }
    return d;
}

void solve() {
    int n, m; cin >> n >> m;
    adj.assign(n + 1, vii{});
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back(pii{v, w});        // neighbor, weight
        adj[v].push_back(pii{u, w});
    }

    vi to_1 = cost(1);
    vi to_n = cost(n);
    // cost from i to 1 is same from 1 to i, can calc all i at same time by
    // setting 1 as the source, precalc it 
    // for (int i = 1; i <= n; i++) {
    //     to_1[i] = cost(i, 1);
    //     to_n[i] = cost(i, n);
    // }

    int sol = INT_MAX;

    for(int u = 1; u <= n; u++) {
        for (auto [v, w] : adj[u]) {
            sol = min(sol, max(to_1[u], max(to_n[v], w)) + w);
        }
    }
    cout << sol << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
