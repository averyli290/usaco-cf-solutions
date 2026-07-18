/*
Problem link: https://codeforces.com/problemset/problem/2137/F
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

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// using namespace __gnu_pbds;

// typedef pair<int, int> node;
// typedef tree<node, null_type, less<node>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_multiset_int;

/*
can set z_i = y_i if there exists a x_j >= y_i, j < i
*/

const int L=2E5+1;
int st[4 * L];

void build(vector<int>& arr, int at=1, int atl=0, int atr=L-1) {
    if (atl == atr) {
        st[at] = arr[atl];
        return;
    }
    int mid = (atl + atr) / 2;
    build(arr, 2 * at, atl, mid);
    build(arr, 2 * at + 1, mid + 1, atr);
    st[at] = max(st[2*at], st[2*at+1]);
}

void update(int ind, int val, int at=1, int atl=0, int atr=L-1) {
    if (atl == atr) {
        st[at] = val;
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update(ind, val, 2 * at, atl, mid);
    else update(ind, val, 2 * at + 1, mid + 1, atr);
    st[at] = max(st[2*at], st[2*at+1]);
}

int query(int s, int e, int at=1, int atl=0, int atr=L-1) {
    if (atr < s || e < atl) return 0;
    if (s <= atl && atr <= e) return st[at];     // at range contained in [s, e] range
    int mid = (atl + atr) / 2;
    int left = query(s, e, 2 * at, atl, mid);
    int right = query(s, e, 2 * at + 1, mid + 1, atr);
    return max(left, right);
}

void solve() {
    ll n; cin >> n;
    fill(all(st), 0);
    vi x(n), y(n);
    vi pref(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        pref[i + 1] = max(pref[i], x[i]);
        update(i, x[i]);
    }
    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }
    ll ans = 0ll;
    ll prev = 0ll;
    for(ll i = 0; i < n; i++) {
        if (x[i] == y[i]) { // any subarray possible
            ans += (i + 1)*(n - i);
        } else if (x[i] < y[i]) {// how many subarrays before have a geq x[j], j < i?
            // need last idx j, j < i s.t. x[j] >= y[i], then there are j + 1 left choices which work
            // there are n - i right choices which work
            ll lo = -1;
            ll hi = i - 1;
            while(lo < hi) {
                ll mid = (lo + hi + 1) / 2;
                if (query(mid, i - 1) >= y[i]) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            ans += (n - i) * (lo + 1ll);
        } else { // x[i] must not be a prefix maximum of this subarray?
            // need the last idx j s.t. x[i] is a pref max, then there are j + 1 left choices which work
            // there are n - i right choices which work
            ll lo = -1;
            ll hi = i - 1;
            // debug(i);
            while(lo < hi) {
                ll mid = (lo + hi + 1) / 2;
                if (query(mid, i - 1) >= x[i]) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            ans += (n - i) * (lo + 1ll);
        }
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
