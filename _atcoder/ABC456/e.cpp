/*
Problem link: https://atcoder.jp/contests/abc456/tasks/abc456_d
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

const long long MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1, vi{});
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) adj[i].push_back(i);
    int w; cin >> w;
    vector<vector<vector<pii>>> adj2(n + 1, vector<vector<pii>>(w, vector<pii>{}));
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < w; j++) {
            if (s[i - 1][j] == 'o') {
                for(int neig : adj[i]) {
                    if (s[neig - 1][(j + 1) % w] == 'o') {
                        adj2[i][j].push_back({neig, (j + 1) % w});
                    }
                }
            }
        }
    }

    vector<vector<bool>> visited(n + 1, vector<bool>(w, false));
    bool done = false;

    function<void(pii)> dfs = [&] (pii cur) {
        if (done) return;
        auto [v, t] = cur;
        cout << v << " " << t << endl;
        if (visited[v][t]) {
            done = true;
            return;
        }
        visited[v][t] = true;
        for(auto p : adj2[v][t]) {
            dfs(p);
        }
    };

    for(int i = 1; i <= n; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j]) {
                dfs({i, j});
            }
        }
    }
    if (done) cout << "Yes" << endl;
    else cout << "No" << endl;

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
