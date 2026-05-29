/*
Problem link: https://codeforces.com/contest/2143/problem/D1
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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;
const long long MOD = 1e9+7;

/*
dp on coloring at least every other edge

include cur -> exclude all which use and have edge to prev

cannot have decreasing subsequence greater than size 2

keep track of previous top 2 distinct values used
dp[i][j][k] = number of ways for using first i elements with j and k as top 2 distnct values
j is largest element selected
k is largest element with a larger element to its left

m[i] = largest elt in prefix up to i

a[i + 1] = cur

for j in [0, i]:
    for j in [0, n]:
        for k in [0, j - 1]:
            // take
            if (cur >= j) then dp[i + 1][cur][k] += dp[i][j][k]
            else if (cur < j && cur >= k) then dp[i + 1][j][cur] += dp[i][j][k] 
            // not take
            dp[i + 1][j][k] += dp[i][j][k]


dp[i+1][j][k] += dp[i][j][k]

if (a[i] >= j > k)
dp[i+1][a[i]][j] += dp[i][j][k]
if (j > a[i] >= k)
dp[i+1][j][a[i]] += dp[i][j][k]

*/

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+2, vector<ll>(n+2, 0LL)));
    dp[0][0][0] = 1LL;
    // for(int i = 0; i < n; i++) dp[i][0][0] = 1LL;
    for(int i = 0; i < n; i++) {
        int cur = a[i];
        // debug(cur);
        for(int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {  // allow for k <= j because 
                // take
                if (cur >= j) {
                    // debug(i);
                    // debug(j);
                    // debug(k);
                    dp[i + 1][cur][k] += dp[i][j][k];
                    dp[i + 1][cur][k] %= MOD;
                } else if (cur < j && cur >= k) {
                    dp[i + 1][j][cur] += dp[i][j][k];
                    dp[i + 1][j][cur] %= MOD;
                }
                // not take
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j][k] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= n; k++) {
            ans += dp[n][j][k];
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
