/*
Avery Li
4/22/2025
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/605031/problem/C
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


/*

use centroid decomposition tree to guarantree that LCA will be within log(n)

5 4
1 2
2 3
2 4
4 5
2 1
2 5
1 2
2 5

0-1-2-3-4

0-1-2
  |
  3-4


*/


vector<vector<int>> adj;
vector<bool> is_removed;
vector<int> subtree_size;

vector<int> ancestor;
vector<int> ans_vec;

/** DFS to calculate the size of the subtree rooted at `node` */
int get_subtree_size(int node, int parent = -1) {
	subtree_size[node] = 1;
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

/**
 * Returns a centroid (a tree may have two centroids) of the subtree
 * containing node `node` after node removals
 * @param node current node
 * @param tree_size size of current subtree after node removals
 * @param parent parent of u
 * @return first centroid found
 */
int get_centroid(int node, int tree_size, int parent = -1) {
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		if (subtree_size[child] * 2 > tree_size) {
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}

/** Build up the centroid decomposition recursively */
void build_centroid_decomp(int node = 0, int p = -1) {
	int centroid = get_centroid(node, get_subtree_size(node));
	ancestor[centroid] = p;

	// do something

	is_removed[centroid] = true;

	for (int child : adj[centroid]) {
		if (is_removed[child]) { continue; }
		build_centroid_decomp(child, centroid);
	}

}

void paint(int v) {
	int cur = v;
	int dist = 0;
	// update all ancestors and self
	while (cur != -1) {
		ans_vec[cur] = min(ans_vec[cur], dist);
		dist++;
		cur = ancestor[cur];
	}
}

void query(int v) {
	int cur = v;
	int dist = 0;
	int ans = ans_vec[v];
	while (cur != -1) {
		ans = min(ans, ans_vec[cur] + dist);
		dist++;
		cur = ancestor[cur];
	}
	ans_vec[v] = ans;

	cout << ans << endl;
}


void solve() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    is_removed.assign(n, false);
    subtree_size.assign(n, 0);

	ancestor.assign(n, -1);
	ans_vec.assign(n, n + 1);

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

	build_centroid_decomp();

	paint(0);

	for(int i = 0; i < m; i++) {
		int t, v; cin >> t >> v;
		v--;
		if (t == 1) {
			paint(v);
		} else {
			query(v);
		}
	}




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
