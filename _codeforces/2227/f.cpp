// #include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <exception>
#include <functional>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <random>
#include <stdexcept>
#include <typeinfo>
#include <utility>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef pair<ll, ll> node;
typedef tree<node, null_type, less<node>,
            rb_tree_tag, tree_order_statistics_node_update> OM_LL; // ordered_multiset_ll

/*
  3
 232
12321

insert greatest to least
update total as you go
reducing height by 1 only affects sum based on towers to the left and greater and equal in height
so we can just insert from greatest to least, left to right
use a segtree instead of OM :(
*/

int L;
vector<int> st;

void update(int ind, int val, int at=1, int atl=0, int atr=L-1) {
    if (atl == atr) {
        st[at] = val;
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update(ind, val, 2 * at, atl, mid);
    else update(ind, val, 2 * at + 1, mid + 1, atr);
    st[at] = st[2*at] + st[2*at+1];
}

int query(int s, int e, int at=1, int atl=0, int atr=L-1) {         // query [s, e] (0-indexed)
    if (atr < s || e < atl) return 0;
    if (s <= atl && atr <= e) return st[at];
    int mid = (atl + atr) / 2;
    int left = query(s, e, 2 * at, atl, mid);
    int right = query(s, e, 2 * at + 1, mid + 1, atr);
    return left + right;
}

void solve() {
    int n; cin >> n;
    vll a(n);
    L = n;
    vector<pll> b(n);
    st.assign(4 * n, 0);            // boots n cats n boots n cats

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {-a[i], i + 1};
    }
    sort(all(b));
    for(int i = 0; i < n; i++) b[i].first = -b[i].first;

    ll tot = 0ll;
    vll subvals(n);

    // OM_LL om;           // omnomnomnom cookie monster
    set<ll> inserted;
    inserted.insert(n + 1);
    // om.insert({n, n + 1});
    for(int i = 0; i < n; i++) {
        auto [h, idx] = b[i];
        // calc total value
        
        ll to_left = query(0, idx - 1);
        // ll to_left = 0ll;
        update(idx, 1);
        // ll to_left = om.order_of_key({h + 1, -1});
        // om.insert(b[i]);
        inserted.insert(idx);
        // if (om.find(b[i]) == om.end()) debug("asdfasdf");
        // auto rightptr = next(om.find(b[i]));     // first stack geq cur to right
        // ll dist_to_right = rightptr->second - idx - 1;
        ll dist_to_right = *next(inserted.find(idx)) - idx - 1;
        // ll dist_to_right = 0ll;
        // tot += h * (dist_to_right - to_left);
        // debug(i);
        // debug(sz(inserted));
        ll num_to_right = sz(inserted) - to_left - 2;
        // debug(num_to_right);
        // debug(to_left);
        tot += h * ((n - idx - num_to_right) - to_left);


        // debug(idx - 1);
        // debug(tot);
        // debug(i);
        // debug(h);
        // debug(idx);
        // debug(to_left);
        // debug(num_to_right);
        // debug(dist_to_right);
        subvals[idx - 1] = to_left - dist_to_right;
        // debug(tot);
    }

    // debug(tot);

    ll mval = tot;
    for(int i = 0; i < n; i++) {
        // debug(i);
        // debug(subvals[i]);
        mval = max(mval, tot + subvals[i]);
    }
    cout << mval << endl;

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
