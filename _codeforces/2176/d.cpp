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
const ll M = 998244353ll;

/*
fib(88) >= 10^18
run each edge ~88 times?
process paths of length 1, then 2, then 3 etc.

dp[vertex][s] = num of paths with ending value s going into vertex

*/

void solve() {
    int n, m; cin >> n >> m;
    vll a(n);
    vector<vi> adj(n, vi{});
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<map<ll, vi>> mp(n, map<ll, vi>{});
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >>y;
        x--; y--;
        adj[x].push_back(y);
        mp[x][a[y]].push_back(y);
        // adj[y].push_back(x);
    }

    vector<map<int, ll>> dp1(n, map<int, ll>{});

    ll ans = 0ll;

    for(int i = 0; i < n; i++) {
        for (int neig : adj[i]) {
            dp1[neig][a[i]]++;
            ans++;
            ans %= M;
        }
    }

    for(int i = 0; i < 88; i++) {
        ll inc = 0ll;
        vector<map<int, ll>> dp2(n, map<int, ll>{});
        for(int v = 0; v < n; v++) {
            for (auto [s, val] : dp1[v]) {
                debug(s);
                ll news = s + a[v];
                for (int w : mp[v][news]) {
                    dp2[w][news] += val;
                    dp2[w][news] %= M;
                    // ans += val;
                    // ans %= M;
                }
            }
            // for (int w : adj[v]) {
            //     dp2[w][a[v]] += dp1[v][a[w] - a[v]];
            // }
        }
        for(int v = 0; v < n; v++) {
            for (auto [key, val] : dp2[v]) {
                ans += val;
                ans %= M;
            }
        }
        dp1 = dp2;
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
