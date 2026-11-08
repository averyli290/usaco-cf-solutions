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

7 2
1 2
2 3
3 7
2 4
4 5
1 6
6 5

1-2-3-7
| |
6 4
  |
  5


7 1
1 2
2 7
1 3
3 4
4 5
5 6
6

1-2-7
|
3
|
4
|
5
|
6
*/


void solve() {

    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1, vi{});
    vector<bool> adj1(n + 1, false);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if (x == 1) {
            adj1[y] = true;
        }
        if (y == 1) {
            adj1[x] = true;
        }
    }

    vi dists(n + 1, 0);

    queue<int> q;
    q.push(n);
    vector<bool> vis(n + 1, false);
    vector<bool> flag(n + 1, false);

    function<void(int, int, bool, int)>dfs = [&] (int cur, int par, bool f, int d) {
        dists[cur] = d;
        flag[cur] = f;
        for(int neig : adj[cur]) {
            if (neig != par) {
                int newf = (cur == 1) ? true : f;
                dfs(neig, cur, newf, d + 1);
            }
        }
    };
    dfs(n, -1, false, 0);

    // bool f = false;
    // while(!q.empty()) {
    //     int cur = q.front();
    //     vis[cur] = true;
    //     q.pop();
    //     if (cur == 1) f = true;
    //     flag[cur] = f;

    //     for(int neig : adj[cur]) {
    //         if (!vis[neig]) {
    //             q.push(neig);
    //             vis[neig] = true;
    //             dists[neig] = dists[cur] + 1;
    //         }
    //     }

    // }

    // for(int i = 1; i <= n; i++) {
    //     cout << dists[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i++) {
    //     cout << flag[i] << " ";
    // }
    // cout << endl;

    int ans = dists[1];
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        if (!adj1[x] && !flag[x]) ans = max(ans, dists[x] + 1);
    }

    cout << ans << endl;

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
