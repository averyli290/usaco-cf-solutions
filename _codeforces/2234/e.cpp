/*
Problem link:
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
const long long M = 1e9+7;

vll factorial;

ll inv(ll a) {
  return a <= 1 ? a : M - (long long)(M/a) * inv(M % a) % M;
}

long long C(ll n, ll k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % M) % M;
}

ll rec(ll l, ll r, vll& a) {
    if (l == r) return 1ll; // base case
    // debug(l);
    // debug(r);
    // there must exist an index idx where a[idx] is equal to the number of intervals
    // containing it within [l,r], note that it will be the minimum also.
    // when we choose, we can repartition based off this minimum
    // because subsequent minimums will not have ranges which cross the minimum
    // chosen at this recurrence level because this one is the smallest by induction
    ll idx = -1ll;
    for (ll i = 0; i < r - l; i++) {                // check from both sides to make faster
        if (a[l + i] == (i + 1) * (r - l - i)) {
            idx = l + i;
            break;
        }
        if (a[r - i - 1] == (i + 1) * (r - l - i)) {
            idx = r - i - 1;
            break;
        }
    }
    // debug(idx);
    // debug(a[idx]);
    if (idx == -1ll) return 0ll;
    // debug(r - l - 1);
    // debug(idx - l);
    ll ans = C(r - l - 1, idx - l);
    // debug(ans);
    ans *= rec(l, idx, a);
    ans %= M;
    ans *= rec(idx + 1, r, a);
    ans %= M;
    // debug(ans);
    return ans;
}

void solve() {
    ll n; cin >> n;
    vll a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    cout << rec(0, n, a) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial.assign(5e5+10, 0ll);
    factorial[0] = 1ll;
    for (int i = 1; i <= 5e5+10; i++) {
        factorial[i] = factorial[i - 1] * i % M;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
