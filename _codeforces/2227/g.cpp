/*
Problem link: https://codeforces.com/contest/2227/problem/G
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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef pair<ll, int> node;
typedef tree<node, null_type, less<node>,
            rb_tree_tag, tree_order_statistics_node_update> OM_LL;


/*
odd length sequence (duh)
after all operations on a good segment is done, we are left with an alternating sum
criteria: alternating sum is greater than 0
lemma: if the alternating sum is greater than 0, then you can compress it to one elt with valid operations
pf: induction, proof by contradiction, there has to exist some index you can compress it on

need binary search and distance, use order statistics
*/

void solve() {
    int n; cin >> n;

    OM_LL e;        // oh mah lawd xD
    OM_LL o;

    vll a(n, 0ll);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << n << endl;
        return;
    }

    // im too tired ot figure this out rn... i'll do it on the plane...
    // my back hurts SO MUCH

    vll sums(n, 0ll);        // sums[i] = alternating sum ending at i, where a[i] is added. sums start from a[1] when i is odd.
    sums[0] = a[0];
    e.insert({a[0], 0});
    sums[1] = a[1];
    ll cursum = a[0];
    for(int i = 2; i < n; i+=2) {   // even sums
        cursum -= a[i - 1];
        cursum += a[i];
        e.insert({cursum, i});
        sums[i] = cursum;
    }

    cursum = a[1];
    o.insert({a[1], 1});
    for(int i = 3; i < n; i+=2) {   // odd sums
        cursum -= a[i - 1];
        cursum += a[i];
        o.insert({cursum, i});
        sums[i] = cursum;
    }

    ll ans = 0ll;
    for(int l = 0; l < n; l++) {        // lowk could have iterated over r... and inserted so no erasing needed...
        // calc ranges [l, r]

        ll targ = sums[l] - a[l];       // alternating sum up to l not including l
        ll curans;
        if (l % 2 == 0) {       // search for even r
            curans = sz(e) - e.order_of_key({targ + 1,-1}); // force alternating sum to be positive
            e.erase(e.lower_bound({sums[l], l}));           // erase the current segment up to l because not considered for future l
        } else {                // search for odd r
            curans = sz(o) - o.order_of_key({targ + 1,-1});
            o.erase(o.lower_bound({sums[l], l}));           // same erase here
        }
        ans += curans;
        // cout << l << " " << ans << endl;
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
