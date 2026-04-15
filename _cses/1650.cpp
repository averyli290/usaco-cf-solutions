/*
https://cses.fi/problemset/task/1650
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

template <class T> class SegmentTree {
  private:
    const T DEFAULT = 0;

    int len;
    vector<T> segtree;  // index 0 is not in use

    T combine(const T &a, const T &b) {
        return a ^ b;
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

    /** @return the minimum element in the range [start, end] */
    T range_query(int start, int end) { return range_query(start, end, 1, 0, len - 1); }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll &i : arr) cin >> i;

    SegmentTree<ll> segtree(arr);
    for (int q = 0; q < k; q++) {
        int a, b; cin >> a >> b;
        cout << segtree.range_query(a - 1, b - 1) << endl;
    }
}