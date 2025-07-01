/*
Avery Li
2/26/2025
Problem link:
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
#include <string>
typedef long long ll;

/*
taking out the vertex with the most edges first is the best no matter what,
easy to see by contradiction

pick the vertex with the highest degree vertex in the resulting forest with similar reasoning.

perform search on the rest

Correct answer: have to try best two vertices for the first vertex in case
use a heap to find the vertices with the highest degrees, try two of them if there is a tie

brute force try all of the other vertices for the second vertex

*/


using namespace std;

int visited_count;

void dfs(vector<bool>& visited, vector<unordered_set<int>> adj, int v) {
    visited[v] = true;
    visited_count++;
    for (auto& ne : adj[v]) {
        if (!visited[ne]) {
            dfs(visited, adj, ne);
        }
    }
}

void solve() {
    int n; cin >> n;
    int x, y;

    vector<unordered_set<int>> adj = vector<unordered_set<int>>(n, unordered_set<int>());

    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--;
        y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    
    int i1, i2;

    int m_index = 0;
    int m_size = adj[0].size();
    for(int i = 1; i < n; i++) {
        if (adj[i].size() > m_size) {
            m_index = i;
            m_size = adj[i].size();
        }
    }
    i1 = m_index;

    //cout << m_index << ' ' << m_size << endl;

    for(int i=0; i < n; i++) {
        if (i != m_index) {
            adj[i].erase(m_index);
        }
    }
    adj[m_index].clear();

    m_index = 0;
    m_size = adj[0].size();
    for(int i = 1; i < n; i++) {
        if (adj[i].size() > m_size) {
            m_index = i;
            m_size = adj[i].size();
        }
    }
    i2 = m_index;

    //cout << m_index << ' ' << m_size << endl;

    for(int i=0; i < n; i++) {
        if (i != m_index) {
            adj[i].erase(m_index);
        }
    }
    adj[m_index].clear();

    vector<bool> visited = vector<bool>(n, false);
    visited[i1] = true; visited[i2] = true;
    visited_count = 0;


    int cc_count = 0;
    
    while (visited_count < n - 2) {
        int start = 0;
        while (visited[start]) start++;
        dfs(visited, adj, start);
        cc_count++;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ':';
    //     for (auto& v:adj[i]) {
    //         cout << v << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << "rem " << i1 << ' ' << i2 << endl;

    cout << cc_count << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
