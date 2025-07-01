/*
Problem link: https://codeforces.com/contest/2112/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

/*
min number is n - 1 (each edge gives exactly one pair), alternate edge direction

-> deg 2 node <- leaf		// find leaf node adj to deg 2 node
-> ->

doesn't work for 
o       o
 \     /
  o-o-o
 /     \
o       o

*/

vector<vector<int>> adj;
vector<vector<int>> sol;
pii to_reverse;

void dfs(int cur, int root, int par = -1, int label = 0) {
	// 0 = outgoing from current, 1 = incoming from par
	if (par != root) {
		if (label == 0) {
			sol[cur].push_back(par);
		} else {
			sol[par].push_back(cur);
		}
	}

	for(int neig : adj[cur]) {
		if (neig != par) {
			dfs(neig, root, cur, (label + 1) % 2);
		}
	}
}

void solve() {
	int n; cin >> n;
	adj.assign(n + 1, vi{});
	for(int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}

	for(int i = 1; i <= n; i++) {
		// find vertex with degree 2
		if (adj[i].size() == 2) {
			int root = i;

			sol.assign(n+1,vi{});

			dfs(adj[root][0], root, root, 0);
			dfs(adj[root][1], root, root, 1);
			sol[adj[root][0]].push_back(root);
			sol[root].push_back(adj[root][1]);

			cout << "YES" << endl;
			for (int i = 1; i < sol.size(); i++) {
				for (int j : sol[i]) {
					cout << i << " " << j << endl;
				}
			}
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
