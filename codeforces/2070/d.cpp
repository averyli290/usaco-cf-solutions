/*
Problem link: https://codeforces.com/problemset/problem/2070/D
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

const ll MOD = 998244353;

vi depth;
vector<vi> depth_list;
vi par;
vector<vi> adj;
vll dp;

void dfs(int cur, int v) {
    depth[cur] = v;
    depth_list[v].push_back(cur);
    for(int neig : adj[cur]) {
        dfs(neig, v + 1);
    }
}

void solve() {
    int n; cin >> n;

    depth.assign(n + 1, 0);
    depth_list.assign(n + 1, vi{});
    par.assign(n + 1, 0);
    adj.assign(n + 1, vi{});
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        par[i] = x;
        adj[x].push_back(i);
    }

    dfs(1, 0LL);
    dp.assign(n + 1, 0LL);
    dp[1] = 1LL;

    queue<int> q;
    q.push(1);
    ll last_level_total = 1;
    int last_depth = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (depth[cur] != last_depth) {
            last_level_total = 0;
            for (int node : depth_list[last_depth]) {
                last_level_total += dp[node];
                last_level_total %= MOD;
            }
        }
        for (int neig : adj[cur]) q.push(neig);
        if (cur == 1) continue;
        dp[cur] = last_level_total;
        dp[cur] %= MOD;
        if (par[cur] != 1) {
            dp[cur] -= dp[par[cur]];
            dp[cur] %= MOD;
        }
        last_depth = depth[cur];
    }

    ll ans = 0LL;
    for (int i : dp) {
        ans += i;
        ans %= MOD;
    }

    ans = (ans + MOD) % MOD;


    cout << ans << endl;

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}