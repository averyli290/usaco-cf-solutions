/*
Problem link: https://codeforces.com/problemset/problem/1579/E2
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


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef pair<int, int> node;
typedef tree<node, null_type, less<node>,
            rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_int;

void solve() {
    int n; cin >> n;
    ordered_multiset_int s;
    ll ans = 0ll;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ll v1 = (ll) (i - s.order_of_key({x, n + 1})); // starts looking at {x + 1, 0} and above
        ll v2 = (ll) s.order_of_key({x, 0}); // starts looking at {x - 1, MAXN} and below
        ans += min(v1, v2);
        s.insert({x, i});
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
