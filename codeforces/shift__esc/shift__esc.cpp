/*
Avery Li
2/26/2025
Problem link: https://codeforces.com/contest/2049/problem/D
*/

/*
if no shifts, move down, then right

DP
dp[i][j] = min cost to get to i,j
dps[i][j][s] = min cost to get to i,j assuming shifted by s

dps[i][j] = dp[i-1][j] + k*s + a[i][(j + s) % m]

dp[i][j] = min(dps[i][j][s]), 0 <= s < m

*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long long>> a;
vector<vector<long long>> dp;
vector<vector<vector<long long>>> dps;
long long n, m, k;
long long MAX = 1e18;

void solve() {
    cin >> n >> m >> k;

    a.assign(n + 1, vector<long long>(m, 0));
    dp.assign(n + 1, vector<long long>(m, MAX));
    dps.assign(n + 1, vector<vector<long long>>(m, vector<long long>(m, MAX)));


    for(long long i = 0 ; i < n; i++) {
        for(long long j = 0; j < m; j++) {
            cin >> a[i + 1][j];
        }
    }

    dp[0][0] = 0;

    for(long long i = 1; i < n + 1; i++){
        for(long long j = 0; j < m; j++){
            for(long long s = 0; s < m; s++) {
                dps[i][j][s] = min(k * s + dp[i - 1][j], dps[i][(j + m - 1) % m][s]) + a[i][(j + s) % m];
            }

            dp[i][j] = *min_element(dps[i][j].begin(), dps[i][j].end());
        }
    }

    // for (long long i = 0; i < n + 1; i++) {
    //     for(long long j = 0; j < m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[n][m - 1] << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;
    while (t--) {
        solve();
    }
    
}
