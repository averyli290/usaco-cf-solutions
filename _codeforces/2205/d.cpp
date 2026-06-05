/*
Problem link: https://codeforces.com/contest/2205/problem/D
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

/*
either increasing (with max elt on right), all decreasing (with max elt on left)
or in v shape (with max elt on either right or left), note this is subproblem identical
to original problem

max cannot be removed, so find index of maxmimum element
then, either remove all elements to right and solve identical problem on left elements
or remove all elements to left and solve identical problem on right elements

recursively solve for left and right subproblems

use segtree to get max element and reverse map to get index


*/

int L;
vector<int> st;

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
    if (atr < s || e < atl ) return 0;
    if (s <= atl && atr <= e) return st[at];     // at range contained in [s, e] range
    int mid = (atl + atr) / 2;
    int left = query(s, e, 2 * at, atl, mid);
    int right = query(s, e, 2 * at + 1, mid + 1, atr);
    return max(left, right);
}

int f(int l, int r, vi& a, vi& idxmap) {
    if (l > r) return 0;
    if (l == r) return 0;
    if (l == r - 1) return 0;
    int idx = idxmap[query(l, r)];
    // left rec
    // debug(l);
    // debug(idx - 1);
    // debug(idx + 1);
    int leftans = (r - idx) + f(l, idx - 1, a, idxmap);
 
    // right rec
    int rightans = (idx - l) + f(idx + 1, r, a, idxmap);
    
    // return 1;
    return min(leftans, rightans);
}

void solve() {
    int n; cin >> n;
    L = n;
    vi a(n), idxmap(n + 1);
    st.assign(4*L, 0);
    int idx;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) idx = i;
        idxmap[a[i]] = i;
    }

    build(a);

    cout << f(0, n-1, a, idxmap) << endl;


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
