/*
https://cses.fi/problemset/task/1651
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

template <typename T> class LazySegtree {
  private:
    const int siz;
    vector<T> tree;
    vector<T> lazy;

    /** applies lazy update to tree[v], places update at lazy[v] */
    void apply(int v, int len, T upd) {
        tree[v] += upd * len;
        lazy[v] += upd;
    }

    /** pushes down lazy updates to children of v */
    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        apply(2 * v, m - l + 1, lazy[v]);
        apply(2 * v + 1, r - m, lazy[v]);
        lazy[v] = 0;
    }

    void range_update(int v, int l, int r, int ql, int qr, int upd) {
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
        return range_query(2 * v, l, m, ql, qr) + range_query(2 * v + 1, m + 1, r, ql, qr);
    }

  public:
    LazySegtree(int n) : siz(n), tree(4 * n), lazy(4 * n) {}

    /** adds to every value on the range [ql, qr] */
    void range_update(int ql, int qr, int upd) { range_update(1, 0, siz - 1, ql, qr, upd); }

    /** @return sum of values on [ql, qr] */
    T range_query(int ql, int qr) { return range_query(1, 0, siz - 1, ql, qr); }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    LazySegtree<ll> segtree(n);
    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        segtree.range_update(i, i, a);
    }

    for (int q = 0; q < k; q++) {
        int type; cin >> type;
        if (type == 1) {
            ll a, b, u; cin >> a >> b >> u;
            segtree.range_update(a-1,b-1, u);
        } else {
            ll a; cin >> a;
            cout << segtree.range_query(a - 1, a - 1) << endl;
        }
    }
}