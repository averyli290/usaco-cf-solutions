/*
Problem link: https://codeforces.com/contest/2063/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<ll>> adj;

ll dfs(ll cur, vector<bool> visited, ll parent, ll exclude) {
	// returns highest degree where exclude is not counted in degree
	visited[cur] = true;
	ll ret = adj[cur].size() - (parent == exclude ? 1 : 0);
	for(ll neig : adj[cur]) {
		if (!visited[neig]) {
			ret = max(ret, dfs(neig, visited, cur, exclude));
		}
	}
	return ret;
}

void solve() {
	ll n; cin >> n;
	adj.assign(n + 1, vector<ll>{});
	for(int i = 0; i < n - 1; i++) {
		ll x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	// try every vertex for first vertex


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}