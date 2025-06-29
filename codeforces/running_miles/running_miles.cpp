/*
Avery Li
4/9/2025
Problem link: https://codeforces.com/contest/1826/problem/D
*/

/*
two of i_1, i_2, i_3 must by l, r

*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n, 0);
    for(int i=0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][2] = a[0]+a[1]+a[2] - 2;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            dp[i][j] = 
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
