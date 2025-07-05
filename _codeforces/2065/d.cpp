/*
Problem link: https://codeforces.com/contest/2065/problem/D
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
Calculate the triangle sum (pref sum) for each array first,
that makes it easier to align the multiplication, and each array
is guaranteed to add that section.
the last value in the prefix sum is the amt that will be multiplied
by when ordering, greedily take the largest ones and put them first
*/

void solve() {
    int n, m; cin >> n >> m;
    ll ans = 0;
    vll vals(n, 0LL);
    for(int i = 0; i < n; i++) {
        ll cur = 0;
        for(int j = 0; j < m; j++) {
            ll x; cin >> x;
            cur += x;
            ans += cur;
        }
        vals[i] = cur;
    }
    sort(all(vals));
    reverse(all(vals));
    for(int i = 1; i < n; i++) {
        ans += vals[i - 1] * (n - i) * m;
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
