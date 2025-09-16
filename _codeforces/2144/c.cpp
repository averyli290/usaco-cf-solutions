/*
Problem link: https://codeforces.com/contest/2144/problem/C
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
const long long MOD = 998244353;


void solve() {
    ll n; cin >> n;
    vll a(n);
    vll b(n);
    for(int i = 0 ; i < n;i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < n;i++) {
        cin >> b[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[0][0] = 1; // no swap
    dp[0][1] = 1; // swap

    for(int i = 1; i < n; i++) {
        if (a[i - 1] <= a[i] && b[i - 1] <= b[i]) {
            dp[i][0] += dp[i - 1][0];
            dp[i][0] %= MOD;
            dp[i][1] += dp[i - 1][1];
            dp[i][1] %= MOD;
        }
        if (a[i - 1] <= b[i] && b[i - 1] <= a[i]) {
            dp[i][1] += dp[i - 1][0];
            dp[i][1] %= MOD;
            dp[i][0] += dp[i - 1][1];
            dp[i][0] %= MOD;
        }
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}