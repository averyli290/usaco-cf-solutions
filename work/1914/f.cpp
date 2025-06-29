/*
Problem link: https://codeforces.com/contest/1914/problem/F
*/

/*
Greedy DFS
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;


vector<int>p;
vector<vector<int>> d;
vector<int>visited;
int dfs(int dist, int cur) {
    if (dist >= 2 && !visited[cur]) {
        return cur;
    }
    for (int n1 : d[cur]) {
        int val = dfs(dist + 1, n1);
        if (val != -1) {
            return val;
        }
    }
    return -1;
}

void solve() {
    int n; cin >> n;
    p.assign(n, 0);
    d.assign(n, vector<int>());
    for(int i = 1; i < n; i++) {
        cin >> p[i];
        p[i] -= 1;
        d[p[i]].push_back(i);
    }
    visited.assign(n, 0);

    // bfs
    queue<int> q;
    q.push(0);
    int ans = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (!visited[cur]) {
            int pairing = dfs(0, cur);
            if (pairing != -1) {
                visited[pairing] = 1;
                visited[cur] = 1;
                cout << "pair: " << cur << " " << pairing << endl;
                ans++;
            }
        }
        for (int n1 : d[cur]) {
            q.push(n1);
        }
    }
    int count = 0;
    for (int v : visited) {
        if (v == 0) {
            count++;
        }
    }
    ans += count / 2;
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
