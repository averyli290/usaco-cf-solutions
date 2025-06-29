/*
Avery Li
XX/XX/XXXX
Problem link:
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void solve() {
    int p; cin >> n >> p;

    adj.assign(n, vector<int>());
    capacity.assign(n, vector<int>(n));


    for (int i = 0; i < p; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] = c;
        //capacity[b][a] = -1 * c;
        capacity[b][a] = 0;
    }

    cout << maxflow(0, n - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
