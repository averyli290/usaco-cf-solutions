/*
Avery Li
4/22/2025
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/605031/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


vector<vector<int>> adj;
vector<bool> is_removed;
vector<int> subtree_size;
vector<char> assignment;
bool possible;

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
void build_centroid_decomp(int node = 0, int depth = 0) {
	int centroid = get_centroid(node, get_subtree_size(node));

	// do something
    //cout << centroid << endl;
    if (depth >= 26) {
        possible = false;
        return;
    }

    assignment[centroid] = 'A' + depth;

	is_removed[centroid] = true;

	for (int child : adj[centroid]) {
		if (is_removed[child]) { continue; }
		build_centroid_decomp(child, depth + 1);
	}

}


void solve() {
    int n;
    cin >> n;

    adj.assign(n, vector<int>());
    is_removed.assign(n, false);
    subtree_size.assign(n, 0);
    assignment.assign(n, '!');

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    possible = true;

    build_centroid_decomp();

    if (possible) {
        for (char c : assignment) {
            cout << c << " ";
        }
        cout << endl;
    } else {
        cout << "Impossible!" << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
