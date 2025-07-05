/*
Problem link: https://codeforces.com/contest/2061/problem/C
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
const int MOD = 998244353;
/*
dp[i][0] = # of configurations of up to i inclusive where i is honest
dp[i][1] = # of configurations of up to i inclusive where i is lying

*/

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int dp[n + 1][2];
    for(int i = 0; i < n + 1; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    dp[0][0] = (a[0] == 0) ? 1 : 0;
    dp[0][1] = 1;
    for(int i = 1; i < n; i++) {
        // i = honest
        // prev lying, one before prev is honest
        if (i == 1 && a[i] == 1) {  // handle i = 1 separately
            dp[i][0] += dp[i - 1][1];
            dp[i][0] %= MOD;
        } else if (i >= 2 && a[i] == a[i - 2] + 1) {
            dp[i][0] += dp[i - 1][1];
            dp[i][0] %= MOD;
        }
        if (a[i] == a[i - 1]) {     // prev honest
            dp[i][0] += dp[i - 1][0];
            dp[i][0] %= MOD;
        }
        // i = lying
        dp[i][1] = dp[i - 1][0];
        dp[i][1] %= MOD;
    }
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i][0] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i][1] << " ";
    // }
    // cout << endl;
    cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
    // cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
