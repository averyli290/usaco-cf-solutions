/*
Avery Li
Problem link: https://codeforces.com/contest/2106/problem/D
4/24/2025
*/


#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    // dp[i][k] = how many flowers can igor collect within the first i flowers,
    // k = 0 => not used power, k = 1 => used power
    int dp[n][2];
    int dp_ans[n][2];

    dp_ans[0][0] = 0;
    dp_ans[0][1] = b[0];

    dp[0][0] = 1 ? a[0] >= b[0] : 0;
    dp[0][1] = 1;

    for (int i = 1; i < n; i++) {
        // int cur_flower = b[dp[i - 1][0]];
        // cout << i << " cur flower: " << cur_flower << endl;

        // if (a[i] >= cur_flower) {
        //     // dont have to use power
        //     dp[i][0] = dp[i - 1][0] + 1;
        //     dp[i][1] = dp[i - 1][1] + 1;

        //     dp_ans[i][0] = dp_ans[i - 1][0];
        //     dp_ans[i][1] = dp_ans[i - 1][1];
        // } else {
        //     // have to use power
        //     dp[i][0] = dp[i - 1][0];
        //     if (dp[i-1][1] == dp[i-1][0]+1) {
        //         dp_ans[i][1] = max(dp_ans[i - 1][1], cur_flower);
        //     } else if (dp[i - 1][1] > dp[i - 1][0] + 1) {
        //         dp_ans[i][1] = dp_ans[i - 1][1];
        //     } else {
        //         dp_ans[i][1] = cur_flower;
        //     }

        // }
    }

    for(int i = 0; i < n; i++) {
        if (dp[i][0] >= m) {
            cout << -1 << endl;
            return;
        }
    }
    int ans = dp[0][1];
    for(int i = 0; i < n; i++) {
        if (dp[i][1] >= m) {
            ans = min(ans, dp_ans[i][1]);
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
