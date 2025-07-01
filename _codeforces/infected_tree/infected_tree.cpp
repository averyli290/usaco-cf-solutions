/*
Avery Li
5/2/2025
Problem link: https://codeforces.com/problemset/problem/1689/C
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

/*

find the closest node to 1 with 1 or 0 children

*/


void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n+1, vector<int>());
    vector<int> visited(n+1, 0);

    for(int i = 0; i < n - 1; i++) {
        int b, c;
        cin >> b >> c;
        a[b].push_back(c);
        a[c].push_back(b);
    }

    queue<pii> q;
    // q stores {cur node, how many dead/infected if path taken to that node (inclusive)}

    q.push(pii{1, 1});
    int dead_inf = n;
    
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        visited[cur.first] = 1;

        int s = 0;
        for(int v : a[cur.first]) {
            if (!visited[v]) { s++; }
        }
        if (s == 0) {
            dead_inf = min(dead_inf, cur.second);     // no more nodes die/infected
        } if (s == 1) {
            dead_inf = min(dead_inf, cur.second + 1); // child node dies
        }
        for (int v : a[cur.first]) {
            if (!visited[v]) {
                q.push(pii{v, cur.second + 2});     // 2 descendants guaranteed to be dead/infected
            }
        }
    }

    cout << n - dead_inf << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
