/*
Problem link:
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*
0 6 8 10 13 14 16 19 25 31

0 3 6 8 10 13 14 16 19 22 25 28 31
*/



void solve() {
    int k; cin >> k;
    vector<vector<vi>> adj;
    for(int i = 0; i < k; i++) {
        int n; cin >> n;
        adj.push_back(vector<vi>(n, vi{}));
        for(int j = 0; j < n - 1;j++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[i][u].push_back(v);
            adj[i][v].push_back(u);
        }
    }
    vi v1(k, 0);
    vi v2(k, 0);

    function<int(int,int,int,int)>dfs = [&] (int t, int cur, int par, int color) {
        int s = 0;
        for(int neig : adj[t][cur]) {
            if (neig != par) {
                s += dfs(t, neig, cur, (color + 1) % 2);
            }
        }
        if (color == 0) s++;
        return s;
    };

    for(int i = 0; i < k; i++) {
        v1[i] = dfs(i, 0, -1, 0);
        v2[i] = sz(adj[i]) - v1[i];
    }

    // if sz(cur tree) >= 2, has a 0 node
    // can connect to all 1 nodes
    vector<array<int, 4>> ans;
    for(int i = 0; i < k; i++) {
        if (sz(adj[i]) >= 2) {
            if (v1[i] > v2[i]) {
                // 0 is used in larger, connect to the smaller one of v1, v2 for others
                for(int j = 0; j < k; j++) {
                    if (i != j) {
                        if (sz(adj[j]) == 1) ans.push_back({i+1, 1, j+1, 1});
                        else {
                            if (v1[j] > v2[j]) ans.push_back({i + 1, 1, j + 1, adj[j][0][0]});
                            else ans.push_back({i + 1, 1, j + 1, 1});
                        }
                    }
                }
            } else {
                // 0 is used in smaller, connect to the larger one of v1, v2 for others
                int use = adj[i][0][0] + 1;
                debug(v1[i]);
                debug(v2[i]);
                for(int j = 0; j < k; j++) {
                    if (i != j) {
                        if (sz(adj[j]) == 1) ans.push_back({i+1, use, j+1, 1});
                        else {
                            if (v1[j] < v2[j]) ans.push_back({i + use, 1, j + 1, adj[j][0][0]});
                            else ans.push_back({i + 1, use, j + 1, 1});
                        }
                    }
                }
            }
            for(auto [x1, x2, x3, x4] : ans) {
                cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
            }
            return;
        }
    }

    for(int i = 2; i <= k; i++) {
        cout << "1 1 " << i << " " << 1 << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
