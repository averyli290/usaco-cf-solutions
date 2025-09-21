/*
Problem link: https://codeforces.com/contest/2143/problem/C
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

/*
1 2 2 1
2 3 3 2

1-2-3
can always get max value from edge, find assignment
*/

vector<vi> adj;
vi ans;
int up;
int down;
void dfs(int cur, map<pii, pii>& val, vector<bool>& vis) {
    vis[cur] = true;
    for(auto v : adj[cur]) {
        if (ans[v] == 0) {
            if (val[pii{cur, v}].first > val[pii{cur, v}].second) {
                ans[v] = down;
                down--;
                dfs(v, val, vis);
            } else {
                ans[v] = up;
                up++;
                dfs(v, val, vis);
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    adj.assign(n + 1, vi{});
    ans.assign(n + 1, 0);
    map<pii, pii> val;
    for(int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        adj[u].push_back(v);
        adj[v].push_back(u);
        val[pii{u, v}] = pii{x, y};
        val[pii{v, u}] = pii{y, x};
    }
    up = 1;
    down = -1;
    ans[1] = 1;
    vector<bool> vis(n + 1, false);
    dfs(1, val, vis);
    ans[1] = 0;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] - down << " ";
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
