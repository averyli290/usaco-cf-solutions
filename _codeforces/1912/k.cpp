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
const long long M = 998244353ll;

/*
0 none
1 o
2 e
3 oo
4 ee
5 eo
6 oe
7 eoo
8 oeo
9 ooe
10 eee
*/

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vll> dp(n + 1, vll(11, 0ll));
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        if (a[i-1] % 2 == 0) {
            dp[i][2] += 1;
            dp[i][4] += dp[i - 1][2];
            dp[i][6] += dp[i - 1][1];
            dp[i][9] += dp[i - 1][3] + dp[i - 1][7];
            dp[i][10] += dp[i - 1][4] + dp[i - 1][10];
            dp[i][2] %= M;
            dp[i][4] %= M;
            dp[i][6] %= M;
            dp[i][9] %= M;
            dp[i][10] %= M;
        } else {
            dp[i][1] += 1;
            dp[i][3] += dp[i - 1][1];
            dp[i][5] += dp[i - 1][2];
            dp[i][7] += dp[i - 1][5] + dp[i - 1][8];
            dp[i][8] += dp[i - 1][6] + dp[i - 1][9];
            dp[i][1] %= M;
            dp[i][3] %= M;
            dp[i][5] %= M;
            dp[i][7] %= M;
            dp[i][8] %= M;
        }
    }
    ll ans = 0ll;
    ans += dp[n][7]; ans %= M;
    ans += dp[n][8]; ans %= M;
    ans += dp[n][9]; ans %= M;
    ans += dp[n][10]; ans %= M;
    cout << ans << endl;
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
