/*
Problem link: https://codeforces.com/problemset/problem/597/C
*/

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

/*
g[i] = # of elts j s.t. a[j] > a[i], j < i
l[i] = # of elts j s.t. a[j] < a[i], j > i

insert from least to greatest, query from idx + 1 to end to get amount of elts less
than current elt and to the right

insert from least to greatest, query from 0 to idx - 1 to get amount of elts greater
than current elt and to the left
*/

template <class T> class SegmentTree {
  private:
    const T DEFAULT = 0LL;          // Default for sum is 0

    int len;
    vector<T> segtree;  // index 0 is not in use

    T combine(const T &a, const T &b) {
        return a + b;
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
        if (at_right < start || end < at_left) { return DEFAULT; }
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

    /** @return the sum of elements in the range [start, end] */
    T range_query(int start, int end) { return range_query(start, end, 1, 0, len - 1); }
};

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    vector<pii> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }

    sort(all(b)); // least to greatest
    reverse(all(b)); // greatest to least

    vll l(n, 1LL);
    ll ans;

    for(int i = 0; i < k + 1; i++) {
        SegmentTree<ll> sg(vll(n, 0LL));
        for(auto& [elt, idx] : b) {
            sg.set(idx, l[idx]);
            l[idx] = sg.range_query(idx + 1, n - 1);
        }
        ans = sg.range_query(0, n-k);
        // if (i == k - 1) {
        //     for(int j = 0; j < n; j++) {
        //         cout << sg.range_query(j, j) << " ";
        //     }
        // }
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
