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


/** A data structure that can answer point update & range max queries. */
template <class T> class SegmentTree {
  private:
    const T DEFAULT = 0;       // CHECK

    int len;
    vector<T> segtree;  // index 0 is not in use

    T combine(const T &a, const T &b) {         // CHECK
        return max(a, b);
    }

    void build(const vector<T> &arr, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = arr[at_left];
            return;
        }
        int mid = (at_left + at_right) / 2;
        build(arr, 2 * at, at_left, mid);
        build(arr, 2 * at + 1, mid + 1, at_right);
        segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
    }

    void set(int ind, T val, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = val;
            return;
        }
        int mid = (at_left + at_right) / 2;
        if (ind <= mid) {
            set(ind, val, 2 * at, at_left, mid);
        } else {
            set(ind, val, 2 * at + 1, mid + 1, at_right);
        }
        segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
    }

    T range_query(int start, int end, int at, int at_left, int at_right) {
        if (at_right < start || end < at_left) { return DEFAULT; }      // CHECK
        if (start <= at_left && at_right <= end) { return segtree[at]; }
        int mid = (at_left + at_right) / 2;
        T left_res = range_query(start, end, 2 * at, at_left, mid);
        T right_res = range_query(start, end, 2 * at + 1, mid + 1, at_right);
        return combine(left_res, right_res);
    }

  public:
    SegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, DEFAULT); };

    SegmentTree(const vector<T> &arr) : len(arr.size()) {
        segtree = vector<T>(len * 4, DEFAULT);
        build(arr, 1, 0, len - 1);
    }

    /** Sets the value at ind to val. */
    void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

    /** @return the maximum element in the range [start, end] */
    T range_query(int start, int end) { return range_query(start, end, 1, 0, len - 1); }
};

int f(int l, int r, vi& a, SegmentTree<int>& st, vi& idxmap) {
    // base cases
    if (l > r) return 0;
    if (l == r) return 0;
    if (l == r - 1) return 0;
    int idx = idxmap[st.range_query(l, r)];
    // left rec
    // debug(l);
    // debug(idx - 1);
    // debug(idx + 1);
    int leftans = (r - idx) + f(l, idx - 1, a, st, idxmap);

    // right rec
    int rightans = (idx - l) + f(idx + 1, r, a, st, idxmap);
    
    // return 1;
    return min(leftans, rightans);
}


void solve() {
    int n; cin >> n;
    vi a(n), idxmap(n + 1);
    int idx;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) idx = i;
        idxmap[a[i]] = i;
    }
    SegmentTree<int> st(a);


    cout << f(0, n-1, a, st, idxmap) << endl;


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
