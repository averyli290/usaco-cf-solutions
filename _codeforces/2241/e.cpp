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
only check subtree and below
count # of paths which start at root of subtree and have square value
given any one of those paths, can choose ANY other vertex 
*/

void solve() {
    int n; cin >> n;
    vll v(n);
    vi p(n);
    vector<vi> adj(n, vi{});
    vector<bool> sq(n, false);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        ll temp = sqrt(v[i]);
        if (temp * temp == v[i] || (temp - 1) * (temp - 1) == v[i] || (temp + 1) * (temp + 1) == v[i]) sq[i] = true;
    }
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y; x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vll subtree(n, 1ll);
    ll ans = 0ll;

    // hi stanley :3
    function<void(int,int)> dfs = [&] (int cur, int par) {

        vector<ll> sizes;
        for(int neig : adj[cur]) {
            if(neig != par) {
                dfs(neig, cur);
                subtree[cur] += subtree[neig];
                sizes.push_back(subtree[neig]);
            }
        }
        if (par != -1) sizes.push_back(n - subtree[cur]);
        vector<ll> dp(3, 0);
        if (sq[cur]) {
            for(ll s : sizes) {
                dp[2] += dp[1] * s;     // add choosing the third point from this subtree
                dp[1] += dp[0] * s;     // add choosing the second point from this subtree
                dp[0] += s;             // add choosing the ... you get it
            }
            // reset and calc, but fix the first point at cur
            dp[0] = 0;
            dp[1] = 0;
            ans += dp[2];
            for(ll s : sizes) {
                dp[1] += dp[0] * s;     // add choosing the third point from this subtree
                dp[0] += s;             // add choosing the second point from this subtree
            }
            ans += dp[1];
        }
    };

    dfs(0, -1);

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
