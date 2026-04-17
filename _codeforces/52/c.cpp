/*
Problem link: https://codeforces.com/problemset/problem/52/C
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

    /** builds the segtree nodes */
    void build(int v, int l, int r, const vector<T> &a) {
        if (l == r) {
            tree[v] = a[l];
            // debug(l);
            // debug(r);
            // debug(tree[v]);
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = min(tree[2 * v], tree[2 * v + 1]);
            // debug(l);
            // debug(r);
            // debug(tree[v]);
        }
    }
    
    /** applies lazy update to tree[v], places update at lazy[v] */
    void apply(int v, int len, T upd) {
        tree[v] += upd;
        lazy[v] += upd;
    }

    /** pushes down lazy updates to children of v */
    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        apply(2 * v, m - l + 1, lazy[v]);
        apply(2 * v + 1, r - m, lazy[v]);
        lazy[v] = 0;
    }

    void range_update(int v, int l, int r, int ql, int qr, ll upd) {
        if (qr < l || ql > r) { return; }
        if (ql <= l && r <= qr) {
            apply(v, r - l + 1, upd);
        } else {
            push_down(v, l, r);
            int m = (l + r) / 2;
            range_update(2 * v, l, m, ql, qr, upd);
            range_update(2 * v + 1, m + 1, r, ql, qr, upd);
            tree[v] = min(tree[2 * v], tree[2 * v + 1]);
        }
    }

    T range_query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) { return LLONG_MAX; }
        if (ql <= l && r <= qr) { return tree[v]; }
        push_down(v, l, r);
        int m = (l + r) / 2;
        return min(range_query(2 * v, l, m, ql, qr), range_query(2 * v + 1, m + 1, r, ql, qr));
    }

  public:
    LazySegtree(int n) : siz(n), tree(4 * n), lazy(4 * n) {}

    LazySegtree(const vector<T> &a) : siz(a.size()), tree(4 * siz), lazy(4 * siz) {
        build(1, 0, siz - 1, a);
    }

    /** adds to every value on the range [ql, qr] */
    void range_update(int ql, int qr, ll upd) { range_update(1, 0, siz - 1, ql, qr, upd); }

    /** @return min of values on [ql, qr] */
    T range_query(int ql, int qr) { return range_query(1, 0, siz - 1, ql, qr); }
};

void solve() {
    int n, m; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    LazySegtree<ll> lsg(a);
    string line;
    getline(cin, line);
    while (m--) {
        getline(cin, line);
        stringstream ss(line);

        vector<ll> vals;
        ll x;
        while (ss >> x) vals.push_back(x);

        if (sz(vals) == 2) {
            int lf = vals[0], rg = vals[1];
            if (lf <= rg) {
                cout << lsg.range_query(lf, rg) << endl;
            } else {
                cout << min(lsg.range_query(lf, n - 1), lsg.range_query(0, rg)) << endl;
            }
        } else if (sz(vals) == 3) {
            int lf = vals[0], rg = vals[1];
            ll v = vals[2];
            // inc operation
            if (lf <= rg) {
                lsg.range_update(lf, rg, v);
            } else {
                lsg.range_update(lf, n - 1, v);
                lsg.range_update(0, rg, v);
            }
        }
    }
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
