/*
Problem link:  https://codeforces.com/contest/1928/problem/B
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
typedef tree<int, null_type, less<int>,
            rb_tree_tag, tree_order_statistics_node_update> OS_INT; // ordered_set_int

void solve() {
    int n; cin >> n;

    OS_INT os;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        os.insert(x);
    }

    int ans = 0;
    for(auto x : os) {
        int right = os.order_of_key(x);
        int left = os.order_of_key(x - (n - 1));
        ans = max(ans, right - left + 1);
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
