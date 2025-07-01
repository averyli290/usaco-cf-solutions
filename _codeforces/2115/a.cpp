/*
Problem link: https://codeforces.com/contest/2115/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
want to find min number of operations to get to gcd(a1, a2, ..., an),
then apply gcd op to rest of n - 1. handle gcd in list at start separately.

dp over all possible numbers for gcd (1 <= gcd <= 5000)
dp[x] = min number of operations to use to obtain x
iterate over all a[i], dp[a[i]] = 0,
can apply gcd operation with a[i] to all numbers j from 1 to 5000,
so dp[gcd(j, a[i])] = min(gcd(j, a[i]), dp[j] + 1)
*/

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int cur_gcd = -1;
    int m = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (cur_gcd == -1) {
            cur_gcd = a[i];
        } else {
            cur_gcd = gcd(cur_gcd, a[i]);
        }
        m = max(m, a[i]);
    }

    int ct = 0;
    for(int i = 0; i < n; i++) {
        if (cur_gcd == a[i]) {
            ct++;
        }
    }
    if (ct > 0) { cout << n - ct << endl; return;}

    vector<int> dp(m + 1, n);

    for(int i = 0; i < n; i++) {
        dp[a[i]] = 0;       // immediately have a[i] in 0 steps
        for (int j = 1; j <= m; j++) {
            int g = gcd(a[i], j);
            dp[g] = min(dp[g], dp[j] + 1);      // can take gcd(a[i], j)
                                                // don't include dp[a[i]] + 1 in min because dp[j]
                                                // isn't necessarily applicable/reachable to apply to a[i]
        }
    }
    cout << dp[cur_gcd] + n - 1 << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
