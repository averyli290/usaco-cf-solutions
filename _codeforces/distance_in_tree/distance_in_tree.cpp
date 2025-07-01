/*
Avery Li
4/21/2025
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/605031/problem/A
*/

/*
1-2-3-4
  |
  5


5 3
1 2
2 3
3 4
4 5

1-2-3-4-5


*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int n, k, ans;
vector<vector<int>> adj;
vector<int> is_removed;     // removed by centroid decomp
vector<int> subtree_size;

int get_subtree_size(int u, int p = -1) {
    subtree_size[u] = 1;
    for (auto v : adj[u]) {
        if (v != p && !is_removed[v]) {
            subtree_size[u] += get_subtree_size(v, u);
        }
    }
    return subtree_size[u];
}

int find_centroid(int u, int tree_size, int p = -1) {
    for (auto v : adj[u]) {
        if (v != p && !is_removed[v]) {
            // check if not centroid
            if (subtree_size[v] * 2 > tree_size) {
                return find_centroid(v, subtree_size[v], u);
            }
        }
    }
    return u;   // return centroid
}

void dfs_paths(int u, int p, int depth, map<int, int>& count) {
    if (depth > k) return; // no need to go deeper
    count[depth]++;
    for (int v : adj[u]) {
        if (v != p && !is_removed[v]) {
            dfs_paths(v, u, depth + 1, count);
        }
    }
}

// gets number of paths in tree with length k with u as a node
int calcPaths(int u) {
    map<int, int> total_count;
    total_count[0] = 1;  // path of length 0 at centroid

    int total = 0;

    for (int v : adj[u]) {
        if (is_removed[v]) continue;
        map<int, int> child_count;
        dfs_paths(v, u, 1, child_count);

        // count paths going through centroid using this child and total_count
        for (auto [d, cnt] : child_count) {
            if (k - d >= 0 && total_count.count(k - d)) {
                total += cnt * total_count[k - d];
            }
        }

        // merge child_count into total_count
        for (auto [d, cnt] : child_count) {
            total_count[d] += cnt;
        }
    }

    return total;
}

void centroid_decomp(int u) {
    int c = find_centroid(u, subtree_size[u]);

    ans += calcPaths(c);    // process

    is_removed[c] = 1;

    // decomp subtrees
    for (auto v : adj[c]) {
        if (!is_removed[v]) {
            centroid_decomp(v);
        }
    }
}

void solve() {
    cin >> n >> k;
    adj = vector<vector<int>>(n + 1, vector<int>());
    is_removed = vector<int>(n + 1, 0);
    subtree_size = vector<int>(n + 1, 0);

    // get trees
    
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // get subtrees values
    int root = 1;
    get_subtree_size(root);

    // Calc answer
    ans = 0;
    centroid_decomp(root);

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}