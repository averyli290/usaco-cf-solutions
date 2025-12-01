/*
Problem link: https://codeforces.com/contest/2005/problem/C
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
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;

/*
dp[i][0] = best score ending with a 'n' using up to i inclusive (1 index)
dp[i][1] = best score ending with a 'a' "
dp[i][2] = best score ending with a 'r' "
dp[i][3] = best score ending with a 'e' "
dp[i][4] = best score ending with a 'k' "
*/

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    string temp = "narek";
    vector<vi> dp(n + 1, vi(5, -10000000));
    dp[0][4]=0; // start with ending at 'k' with score 0
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {    // skip string
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
        int curscorestart = 0;
        for(int j = 0; j < m; j++) { // sub off whole string val at start
            if (temp.find(a[i][j]) < 5) curscorestart--;
        }
        for (int start = 0; start < 5; start++) {
            int cur = (start + 1) % 5; // looking for this, ended at cur - 1 index of "narek"
            // int curscore = -cur + curscorestart;
            // int curscore = curscorestart;
            int curscore = curscorestart + dp[i][start];        // current score
            // debug(start);
            // debug(curscore);
            // debug(curscorestart);
            for(int j = 0; j < m; j++) {
                if (a[i][j] == temp[cur]) {
                    cur = (cur + 1) % 5;
                    if (cur == 0) curscore += 10;       // -5 to 5
                }
                // debug(cur);
                // debug(curscore);
                // debug(a[i][j]);
                // dp[i + 1][cur] = max(dp[i + 1][cur], dp[i][(start + 4) % 5] + curscore);
                dp[i + 1][(cur + 4) % 5] = max(dp[i + 1][(cur + 4) % 5], curscore); // ending at prev val of cur (cur - 1) mod 5
            }
        }
    }

    // for (int j = 0; j < n + 1; j++) {
        // for (int i = 0; i < 5; i++) {
            // cout << dp[j][i] << " ";
        // }
        // cout << endl;
    // }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = max(ans, dp[n][i] - ((i + 1) % 5));
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
