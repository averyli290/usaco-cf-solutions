/*
Problem link: https://codeforces.com/contest/2139/problem/B
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
3 4
1 10 10

1 10 10 -> 3
1 20 10 -> 1
1 30 20 -> 2
1 10 30 -> 3

10+1+30+30 = 71


1 10 10 -> 3
1 20 10 -> 2
1 10 20 -> 3
1 20 10 -> 2
10+20+20+20=70

*/

void solve() {
    int n, m; cin >> n >> m;
    vll a(n);
    ll s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i] * n;
    }
    sort(all(a));
    ll ans = m / n * s;
    ll ctr = 1;
    // cout << ans << endl;
    // cout << n - (m % n) << endl;
    if (m >= n) {
    for(int i = 0; i < n - (m % n); i++) {
        ans -= a[i] * (n - (m % n) - i - 1);
    }

    }
    for(int i = n - (m % n); i < n; i++) {
        ans += a[i] * ctr;
        ctr++;
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
