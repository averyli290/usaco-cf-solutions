/*
Problem link: https://codeforces.com/contest/1914/problem/D
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
000 = 0
001 = 1
010 = 2
011 = 3
100 = 4
101 = 5
110 = 6
111 = 7

*/

void solve() {
    int n; cin >> n;
    vll a(n), b(n), c(n);

    vector<vector<ll>> dp(n + 1, vector<ll>(8, 0ll));
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) {
        dp[i][1] = max(dp[i - 1][1], a[i - 1]);
        dp[i][2] = max(dp[i - 1][2], b[i - 1]);
        dp[i][4] = max(dp[i - 1][4], c[i - 1]);
        dp[i][3] = max(dp[i - 1][3], max(dp[i - 1][1] + b[i - 1], dp[i - 1][2] + a[i - 1]));
        dp[i][5] = max(dp[i - 1][5], max(dp[i - 1][1] + c[i - 1], dp[i - 1][4] + a[i - 1]));
        dp[i][6] = max(dp[i - 1][6], max(dp[i - 1][2] + c[i - 1], dp[i - 1][4] + b[i - 1]));
        dp[i][7] = max(dp[i - 1][7], max(max(dp[i - 1][3] + c[i - 1], dp[i - 1][5] + b[i - 1]), dp[i - 1][6] + a[i - 1]));
    }
    cout << dp[n][7] << endl;
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
