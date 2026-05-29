/*
Problem link: https://atcoder.jp/contests/abc456/tasks/abc456_d
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

const long long MOD = 998244353;

void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<vll> dp(n + 1, vll(3, 0LL));
    for(int i = 0; i < n; i++) {
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
        dp[i + 1][2] = dp[i][2];
        if (s[i] == 'a') {
            dp[i + 1][0] += dp[i][1] + dp[i][2] + 1;
            dp[i + 1][0] %= MOD;
        } else if (s[i] == 'b') {
            dp[i + 1][1] += dp[i][0] + dp[i][2] + 1;
            dp[i + 1][1] %= MOD;
        } else {
            dp[i + 1][2] += dp[i][0] + dp[i][1] + 1;
            dp[i + 1][2] %= MOD;
        }
    }
    cout << (dp[n][0] + dp[n][1]  + dp[n][2]) % MOD << endl;
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
