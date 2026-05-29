/*
Problem link: https://codeforces.com/problemset/problem/2050/G
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

dp[i] = # of connected components in subtree after removing a path which ends at current node


dp[i] = max(# of children - 1 + max over [ dp[child] ], # of children)

ans[i] = max(
# of adj nodes,
dp[i],
# of adj nodes - 1 + max over { dp[child] },
# of adj nodes - 2 + 2 top over { dp[child] }
)

2 1
3 2
4 2
5 3
6 4

1-2-3-5
  |
  4-6
  |
  7

1
7
1 2
2 3
3 5
2 4
4 6
4 7

*/

void solve() {
    int n; cin >> n;
    vector<vi> adj(n + 1, vi{});
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    vi dp(n + 1, 0);
    vi ans(n + 1, 0);

    int tot = 0;
    function<void(int, int)> dfs = [&] (int cur, int par) {
        if (sz(adj[cur]) == 1 && par != -1) {   // handle leaf
            dp[cur] = 0;
            ans[cur] = 1;
            return;
        }
        int numchildren = 0;
        vi children_vals;
        for(int child : adj[cur]) { // get all children values in list
            if (child == par) continue;
            dfs(child, cur);
            children_vals.push_back(dp[child]);
            numchildren++;
        }
        sort(all(children_vals));
        // calc dp and ans for current
        dp[cur] = max((numchildren - 1) + children_vals[numchildren - 1], numchildren);
        ans[cur] = max(sz(adj[cur]), dp[cur]);
        if (numchildren >= 1) ans[cur] = max(ans[cur], sz(adj[cur]) - 1 + children_vals[numchildren - 1]);      // ends at current
        if (numchildren >= 2) ans[cur] = max(ans[cur], sz(adj[cur]) - 2 + children_vals[numchildren - 1] + children_vals[numchildren - 2]); // path thru current
        tot = max(tot, ans[cur]);
    };

    // root at 1
    dfs(1, -1); // -1 parent => node is root
    cout << tot << endl;
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
