/*
Problem link: https://codeforces.com/problemset/problem/61/E
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
    int n; cin >> n;
    vi a(n);
    vector<pii> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }

    vll g(n);
    vll l(n);
    sort(all(b)); // least to greatest
    SegmentTree<ll> sg1(vll(n, 0LL));
    for(auto& [elt, idx] : b) {
        sg1.set(idx, 1LL);
        l[idx] = sg1.range_query(idx + 1, n - 1);
    }
    reverse(all(b)); // greatest to least
    SegmentTree<ll> sg2(vll(n, 0LL));
    for(auto& [elt, idx] : b) {
        sg2.set(idx, 1LL);
        g[idx] = sg2.range_query(0, idx - 1);
    }
    ll tot = 0LL;
    for(int i = 1; i < n - 1; i++) {
        tot += l[i] * g[i];
    }
    cout << tot << endl;



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
