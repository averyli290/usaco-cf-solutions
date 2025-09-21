/*
Problem link: https://codeforces.com/contest/2143/problem/D
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
const long long MOD = 1e9+7;

/*
dp on coloring at least every other edge

include cur -> exclude all which use and have edge to prev

keep track of previous top 2 distinct values used
dp[i][j][k] = number of ways for using first i elements with j and k as top 2 distnct values

a[i] = current value
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
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(301, vector<ll>(301, 0LL)));
    dp[0][0][0] = 1LL;
    //for(int i = 0; i < n; i++) dp[i][0][0] = 1LL;
    for(int i = 0; i < n; i++) {
        int cur = a[i];
        for(int j = 0; j < 301; j++) {
            if (j == 0) {
                dp[i + 1][cur][0] += dp[i][0][0];
                dp[i + 1][cur][0] %= MOD;
            }
            for(int k = 0; k < j; k++) {
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j][k] %= MOD;
                if (cur >= j){
                    dp[i + 1][cur][j] += dp[i][j][k];
                    dp[i + 1][cur][j] %= MOD;
                }
                if (j > cur && cur >= k){
                    dp[i + 1][j][cur] += dp[i][j][k];
                    dp[i + 1][j][cur] %= MOD;
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j < 301; j++) {
        for (int k = 0; k < 301; k++) {
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
