/*
Problem link: https://codeforces.com/contest/1389/problem/B
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
    int n, k, z; cin >> n >> k >> z;
    vll a(n);
    vector<vector<vll>> dp(k + 1, vector<vll>(z + 1, vll(2,0ll)));     // dp[x][y] = x moves, having moved left y times
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0][0][0] = a[0];
    dp[0][0][1] = a[0];

    ll ans = 0ll;
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= z; j++) {
            if (i > 0 && i > 2 * j) {
                // cout << endl;
                // debug(dp[i][j]);
                // debug(dp[i-1][j]);
                // debug(a[i-j]);
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + a[i - 2 * j]);
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + a[i - 2 * j]);
            }
            if (j < z && i >= (j + 1) * 2) {        // can move left;
                // debug(i);
                // debug(j);
                // debug(i - j - 1);
                // debug(a[i - j - 1 - 1]);
                dp[i][j + 1][0] = max(dp[i][j + 1][0], dp[i - 1][j][1] + a[i - 1 - j - 1]);
                // if (i < k) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[]);
                // debug(dp[i][j + 1]);
                // debug(i);
                // debug(j + 1);
            }
            ans = max(ans, dp[i][j][0]);
            ans = max(ans, dp[i][j][1]);
            // if (i < k) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1]);
            // cout << i << "," << j << ":";
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
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
