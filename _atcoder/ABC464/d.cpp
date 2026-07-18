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

/*
dp[i][0] = max ending at i, with it being sunny
dp[i][1] = max ending at i, with it being rainy
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi a(n);
    for(int i = 0; i < n; i++) {
        if (s[i] == 'S') a[i] = 0;
        else a[i] = 1;
    }

    vll x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n - 1; i++) cin >> y[i];

    vector<vll> dp(n, vll(2, 0ll));

    if (a[0] == 0) {
        dp[0][0] = 0;
        dp[0][1] = -x[0];
    } else {
        dp[0][0] = -x[0];
        dp[0][1] = 0;
    }
    for(int i = 1; i < n; i++) {
        if (a[i] == 0) {    // 
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + y[i - 1]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) - x[i];
        } else {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + y[i - 1]) - x[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
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
