/*
Problem link: https://www.spoj.com/problems/HORRIBLE/
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
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }
    
    /** applies lazy update to tree[v], places update at lazy[v] */
    void apply(int v, int len, ll upd) {
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

    void range_update(int v, int l, int r, int ql, int qr, ll upd) {
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

    LazySegtree(const vector<T> &a) : siz(a.size()), tree(4 * siz), lazy(4 * siz) {
        build(1, 0, siz - 1, a);
    }

    /** adds to every value on the range [ql, qr] */
    void range_update(int ql, int qr, ll upd) { range_update(1, 0, siz - 1, ql, qr, upd); }

    /** @return sum of values on [ql, qr] */
    T range_query(int ql, int qr) { return range_query(1, 0, siz - 1, ql, qr); }
};

void solve() {
    int n, c; cin >> n >> c;
    vll a(n);
    // for(ll& v : a) cin >> v;
    LazySegtree<ll> lst(a);
    while(c--) {
        ll type, p, q, v;
        cin >> type >> p >> q;
        p--; q--;
        if (type == 0) {
            cin >> v;
            lst.range_update(p,q,v);
        } else {
            cout << lst.range_query(p,q) << endl;
        }
    }
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
