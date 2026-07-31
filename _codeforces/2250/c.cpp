/*
Problem link: https://codeforces.com/contest/2250/problem/C
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
https://www.youtube.com/watch?v=9qN9EF-6IcI

can greedily pick subsequence without bad things happening
fix the restriction on the positions by iterating over the length of the subsequence
*/

void solve() {
    int n; cin >> n;
    vi l(n), r(n), u(n), v(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> u[i] >> v[i];
    }

    int ans = 0;
    for (int m = 1; m <= n; m++) {
        // debug(m);
        int ct = 0;
        for(int i = 1; i <= n; i++) {
            // cout << l[i - 1] << " " << r[i-1] << " " << u[i - 1] << " " << v[i-1] << endl;
            if ((ct + 1 < l[i-1] || ct + 1> r[i-1]) && (m - (ct + 1) + 1 < u[i-1] || m - (ct + 1) + 1 > v[i-1])) ct++;
            // cout << i << endl;
            if (ct >= m) break;
            // cout << ct << endl;
        }
        // debug(ct);
        if (ct >= m) ans = ct;
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
