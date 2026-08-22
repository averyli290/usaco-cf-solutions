/*
Problem link: https://codeforces.com/contest/2254/problem/E
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
            rb_tree_tag, tree_order_statistics_node_update> OM_LL; // ordered_multiset_ll

/*
https://www.youtube.com/watch?v=9qN9EF-6IcI


-3 4 2 -1 1 0
1
-3 4 2 -1 1 0
-3 4 2 -1 1 0


-3 -1 0 1 2 4 
1
-3 -1 0 2 4 
1 1
-3 -1 2 4 
1 1 3
-3 -1 4 

*/


void solve() {
    int n; cin >> n;
    vll b(n);
    OM_LL bb;
    
    for(int i= 0; i< n; i++) {
        cin >> b[i];
        bb.insert({b[i], i});
    }

    ll ssum = accumulate(all(b), 0ll);
    vll ans(n);

    ll prev = 0ll;
    for(int i = 0; i < n; i++) {
        int lo = 0;
        int hi = sz(bb);
        auto ptr = bb.begin();
        ll nextval = -1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            auto tempptr = bb.find_by_order(mid);
            ll cur = tempptr->first;
            ll temp = ssum - cur;
            ll next = prev + cur;      // val to check
            if(next + temp > 0 && next > 0) {
                hi = mid;
                nextval = next;
                ptr = tempptr;
            } else {
                lo = mid + 1;
            }
        }
        if (nextval == -1) {
            cout << -1 << endl;
            return;
        }
        ans[i] = nextval;
        ssum -= ptr->first;
        bb.erase(ptr);
        prev = ans[i];
    }
    for(ll v : ans) {
        cout << v << " ";
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
