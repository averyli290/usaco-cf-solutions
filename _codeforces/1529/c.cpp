/*
Problem link: https://codeforces.com/contest/1529/problem/C
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


void solve() {
    int n; cin >> n;
    vector<vi> adj(n, vi{});
    vll l(n), r(n);
    for(int i=0;i< n; i++) cin >> l[i] >> r[i];
    for(int i=0;i< n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<pll> dp(n, pll{0, 0});       // .first is max value at subtree at i from choosing left bound, .second is for right bound
    function<void(int,int)> dfs = [&] (int cur, int par) {
        for(int neig : adj[cur]) {
            if (neig != par) {
                dfs(neig, cur);
            }
        }
        // check between choosing left and right boundaries
        for(int neig : adj[cur]) {
            if (neig != par) {
                dp[cur].second += max(dp[neig].first + abs(r[cur] - l[neig]), dp[neig].second + abs(r[cur] - r[neig]));
                dp[cur].first += max(dp[neig].first+ abs(l[cur] - l[neig]), dp[neig].second + abs(l[cur] - r[neig]));
            }
        }
    };
    dfs(0, -1);
    cout << max(dp[0].first, dp[0].second) << endl;
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