/*
Problem link: https://codeforces.com/contest/2147/problem/C
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

/*
01010101
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    vector<int> a(n);
    vector<vi> dp(n, vi(2, 0));
    // dp[i][j] = works for up to and including i with i jumping in j direction  (left = 0, right = 1)

    for(int i = 0; i < n; i++) a[i] = s[i] == '0' ? true : false;
    
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i = 1; i < n; i++) {
        if (!a[i]) { // x0
            if (a[i - 1]) { // 10
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][0];
            } else { // 00
                dp[i][0] = dp[i - 1][0] || dp[i - 1][1];
                dp[i][1] = dp[i - 1][0] || dp[i - 1][1];
            }
        } else { // x1
            dp[i][1] = dp[i - 1][0] || dp[i - 1][1]; // can always jump right
            if (a[i - 1]) { // 11
                dp[i][0] = dp[i - 1][0] || dp[i - 1][1];
            } else { // 01
                if (i >= 2 && a[i - 2]) {
                    dp[i][0] = dp[i - 2][1];
                }
            }
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout << i << " " << a[i] << ": ";
    //     for(int j = 0; j < 2; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (dp[n - 1][0] || dp[n - 1][1]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
