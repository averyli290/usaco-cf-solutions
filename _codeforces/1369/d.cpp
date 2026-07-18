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
const long long M = 1e9+7;


void solve() {
    int q; cin >> q;
    vi ns(q);
    for(int i=0; i < q; i++) {
        cin >> ns[i];
    }
    int n = *max_element(all(ns));
    vector<vll> dp(max(5, n + 1), vll(2, 0ll));
    dp[1] = {0ll, 0ll};
    dp[2] = {0ll, 0ll};
    dp[3] = {0ll, 4ll};
    dp[4] = {4ll, 4ll};
    for(int i = 5; i <= n; i++) {
        dp[i][0] = ((2 * max(dp[i - 2][0], dp[i - 2][1])) % M + max(dp[i-1][0],dp[i-1][1])) % M;
        dp[i][1] = ((2 * dp[i - 2][0]) % M + dp[i-1][0] + 4) % M;
    }

    for(int x : ns) cout << max(dp[x][0], dp[x][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
