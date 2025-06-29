/*
Problem link: https://codeforces.com/contest/2114/problem/E
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

vector<ll> max_t;
vector<ll> min_t;
vector<int> visited;
vector<vector<int>> e;
vector<ll> a;

void dfs(int cur, int parent = -1) {
    if (visited[cur]) {
        return;
    }
    visited[cur] = 1;
    if (parent == -1) {
        max_t[cur] = a[cur];
        min_t[cur] = a[cur];
        //cout << cur << " " << max_t[cur] << " " << min_t[cur] << endl;
    } else {
        max_t[cur] = max(a[cur], a[cur] - min_t[parent]);
        min_t[cur] = min(a[cur], a[cur] - max_t[parent]);
        //cout << cur << " " << max_t[cur] << " " << min_t[cur] << endl;
    }
    for (int child : e[cur]) {
        if (!visited[child]) {
            dfs(child, cur);
        }
    }
}

void solve() {
    int n; cin >> n;
    a.assign(n, 0);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    max_t.assign(n, 0LL);
    min_t.assign(n, LLONG_MAX);
    visited.assign(n, 0);
    e.assign(n, vector<int>());

    for (int i = 0; i < n - 1; i++) {
        int v, u; cin >> v >> u;
        v--; u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        cout << max_t[i] << ' ';
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
