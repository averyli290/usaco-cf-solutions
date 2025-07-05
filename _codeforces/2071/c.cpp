/*
Problem link: https://codeforces.com/contest/2071/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;

vector<vi> depth_vecs;
vector<vi> adj;

void dfs(int cur, int par = -1, int depth = 0) {
    //cout << cur << endl;
    depth_vecs[depth].push_back(cur);
    for (int neig : adj[cur]) {
        if (neig != par) {
            dfs(neig, cur, depth + 1);
        }
    }
}

void solve() {
    int n, st, en; cin >> n >> st >> en;
    depth_vecs.assign(n+1, vi{});
    adj.assign(n+1, vi{});

    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }

    dfs(en);

    for(int i = n; i >= 0; i--) {
        for (int v : depth_vecs[i]) {
            cout << v << " ";
        }
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
