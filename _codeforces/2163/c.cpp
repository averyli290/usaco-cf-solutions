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
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;

/*
prefix min and max
suffix min and max

count how many don't exist
*/


void solve() {
    int n; cin >> n;
    vector<vi> a(2, vi(n, 0));
    vi pmin(n + 1, INT_MAX);
    vi pmax(n + 1, 0);
    vi smin(n + 1, INT_MAX);
    vi smax(n + 1, 0);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        pmin[i + 1] = min(pmin[i], a[0][i]);
        pmax[i + 1] = max(pmax[i], a[0][i]);
    }
    for(int i = n; i > 0; i--) {
        smin[i - 1] = min(smin[i], a[1][i - 1]);
        smax[i - 1] = max(smax[i], a[1][i - 1]);
    }
    vector<int> dp(2 * n + 1, INT_MAX);
    for(int i = 0; i < n; i++) {
        int lower = min(pmin[i + 1], smin[i]);
        int upper = max(pmax[i + 1], smax[i]);
        dp[lower] = min(dp[lower], upper);          // update the ranges for each lower, keep the min upper which is possible
        if (i == 2) {
            debug(a[0][i]);
            debug(a[1][i]);
            debug(lower);
            debug(upper);
        }
    }
    ll ans = 0;
    for(int i = 1; i <= 2*n; i++) {
        debug(i);
        debug(dp[i]);
        if (dp[i] != INT_MAX) {
            ans += i * (2 * n - dp[i] + 1);
        }
    }
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
