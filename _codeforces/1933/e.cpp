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


void solve() {
    ll n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vll pref(n + 1, 0ll);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    int q; cin >> q;
    while (q--) {
        ll l, u; cin >> l >> u;
        ll lo = l;
        ll hi = n;
        int ctr = 0;
        while (lo < hi) {
            // if (ctr > 10) break;
            // ctr++;
            ll mid = (hi + lo + 1) / 2;
            // debug(mid);
            // debug(lo);
            // debug(hi);
            // debug(l);
            // debug(pref[mid] - pref[l - 1]);
            if (pref[mid] - pref[l - 1] <= u) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
            // debug(mid);
        }
        // debug(lo);

        ll diff = u - (pref[lo] - pref[l - 1]);
        ll val1 = (u + 1) * u / 2 - (diff + 1) * diff / 2;
        // debug(val1);
        ll ans = lo;
        if (lo < n) {
            diff = pref[lo + 1] - pref[l - 1] - (u + 1);
            // debug(diff);
            ll val2 = (u + 1) * u / 2 - (diff + 1) * diff / 2;
            // debug(val2);
            if (val2 > val1) {
                ans = lo + 1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
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
