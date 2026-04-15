/*
https://cses.fi/problemset/task/1735
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
pii upd
*/

template <typename T> class LazySegtree {
  private:
    const int siz;
    vector<T> tree;
    vector<pll> lazy;

    /** builds the segtree nodes */
    void build(int v, int l, int r, const vector<T> &a) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    /** applies lazy update to tree[v], places update at lazy[v] */
    void apply(int v, int len, pll upd) {
        // 1 = ADD, 2 = SET
        if (upd.first == 1) {
            if (lazy[v].first != 2) {       // not SET
                lazy[v] = {1, lazy[v].second + upd.second};
            } else {
                lazy[v].second += upd.second;
            }
            tree[v] += upd.second * len;
            // lazy[v].second += upd.second;
        } else if (upd.first == 2) {
            tree[v] = upd.second * len;
            lazy[v] = upd;
        }
    }

    /** pushes down lazy updates to children of v */
    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        apply(2 * v, m - l + 1, lazy[v]);
        apply(2 * v + 1, r - m, lazy[v]);
        lazy[v] = pll{0, 0};
    }

    void range_update(int v, int l, int r, int ql, int qr, pll upd) {
        if (qr < l || ql > r) { return; }
        if (ql <= l && r <= qr) {
            apply(v, r - l + 1, upd);
        } else {
            push_down(v, l, r);
            int m = (l + r) / 2;
            range_update(2 * v, l, m, ql, qr, upd);
            range_update(2 * v + 1, m + 1, r, ql, qr, upd);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    T range_query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) { return 0; }
        if (ql <= l && r <= qr) { return tree[v]; }
        push_down(v, l, r);
        int m = (l + r) / 2;
        // combine = sum
        return range_query(2 * v, l, m, ql, qr) + range_query(2 * v + 1, m + 1, r, ql, qr);
    }

  public:
    LazySegtree(int n) : siz(n), tree(4 * n), lazy(4 * n) {}

    LazySegtree(const vector<T> &a) : siz(a.size()), tree(4 * siz), lazy(4 * siz) {
        build(1, 0, siz - 1, a);
    }

    /** adds to every value on the range [ql, qr] */
    void range_update(int ql, int qr, pll upd) { range_update(1, 0, siz - 1, ql, qr, upd); }

    /** @return sum of values on [ql, qr] */
    T range_query(int ql, int qr) { return range_query(1, 0, siz - 1, ql, qr); }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    LazySegtree<ll> segtree(arr);

    for (int q = 0; q < k; q++) {
        int type; cin >> type;
        ll a, b, u; cin >> a >> b;
        a--; b--;
        if (type == 1) {
            cin >> u;
            segtree.range_update(a,b, {1, u});
        } else if (type == 2) {
            cin >> u;
            segtree.range_update(a,b, {2, u});
        } else {
            cout << segtree.range_query(a, b) << endl;
        }
    }
}