/*
Problem link: https://codeforces.com/contest/2230/problem/D
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

dp[i][0] = # of starting idxs <= i st. we end on idx i and dont watch i
dp[i][1] = # of starting idxs <= i st. we end on idx i and watch i

*/


void solve() {
    int n; cin >> n;
    vi a(n), b(n), prefa(n), prefb(n);
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0 ;i < n; i++) cin >> b[i];
    a.insert(a.begin(), -1);
    b.insert(b.begin(), -1);
    vector<vll> dp(n + 1, vll(2, 0ll));
    ll ans = 0ll;
    dp[0][0] = 0ll;
    dp[0][1] = 1ll;
    for(int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            dp[i][1] = 0ll; // def cant take if diff
            if (!(a[i] == a[i - 1] + 1 || b[i] == b[i - 1] + 1)) {
                dp[i][0] += dp[i - 1][1];
            }
        } else {
            if (a[i] == 1) dp[i][1]++;
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        }
        ans += dp[i][0] + dp[i][1];
    }
    for(int i = 0; i<= n; i++) {
        cout << dp[i][0] << " ";
    }
    cout << endl;
    for(int i = 0; i<= n; i++) {
        cout << dp[i][1] << " ";
    }
    cout << endl;
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
