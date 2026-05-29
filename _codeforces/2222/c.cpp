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
note that medians must be m, which is median of whole array
dp[i] max number of odd size partitions with m as median up to index i
*/

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    vi b = a;
    sort(all(b));
    int m = b[n / 2];

    vi dp(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        // debug(i);
        int less = 0;
        int eq = 0;
        int tot = 0;
        for(int j = i; j <= n; j++) {
            if (a[j - 1] < m) less++;
            else if(a[j - 1] == m) eq++;
            tot++;
            
            // check if median of current subarray is m
            // check that the preceding subarray has valid partition (default true if i=1) and odd length
            if(tot % 2 == 1 && (i == 1 || dp[i - 1] > 0)) {     
                if(tot == 1) {
                    if (eq == 1) {
                        dp[j] = max(dp[j], dp[i - 1] + 1);
                    }
                } else if (less < (tot + 1) / 2 && less + eq >= (tot + 1) / 2) {
                    // debug(less);
                    // debug(eq);
                    // debug(tot);
                    // debug(i);
                    // debug(j);
                    // debug(dp[i - 1]);
                    dp[j] = max(dp[j], dp[i - 1] + 1);      // add current subarray a[i,j] to dp[1,i-1]
                }
            }
        }
    }
    // for(int i : dp) {
    //     cout << i << " ";
    // }
    // cout << endl;
    cout << dp[n] << endl;
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
