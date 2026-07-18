#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// SUM

template <typename T> class LazySegtree {
  private:
    const int siz;
    vector<T> tree;
    vector<T> lazy;

    /** builds the segtree nodes */
    void build(int v, int l, int r, const vector<T> &a) {
        if (l == r) {
            tree[v] = a[l];         // CHECK
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = tree[2 * v] + tree[2 * v + 1];        // CHECK
        }
    }
    
    /** applies lazy update to tree[v], places update at lazy[v], doesn't interact with children */
    void apply(int v, int len, T upd) {
        tree[v] += upd * len;       // CHECK
        lazy[v] += upd;             // CHECK
    }

    /** pushes down lazy updates to children of v */
    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        apply(2 * v, m - l + 1, lazy[v]);
        apply(2 * v + 1, r - m, lazy[v]);
        lazy[v] = 0;                        // CHECK
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
            tree[v] = tree[2 * v] + tree[2 * v + 1];            // CHECK
        }
    }

    T range_query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) { return 0; }             // CHECK
        if (ql <= l && r <= qr) { return tree[v]; }     // CHECK
        push_down(v, l, r);
        int m = (l + r) / 2;

        // CHECK
        return range_query(2 * v, l, m, ql, qr) + range_query(2 * v + 1, m + 1, r, ql, qr);
    }

  public:
    LazySegtree(int n) : siz(n), tree(4 * n), lazy(4 * n) {}

    LazySegtree(const vector<T> &a) : siz(a.size()), tree(4 * siz), lazy(4 * siz) {
        build(1, 0, siz - 1, a);
    }

    /** adds to every value on the range [ql, qr] */
    void range_update(int ql, int qr, int upd) { range_update(1, 0, siz - 1, ql, qr, upd); }

    /** @return sum of values on [ql, qr] */
    T range_query(int ql, int qr) { return range_query(1, 0, siz - 1, ql, qr); }
};


// MAX


template <typename T> class LazySegtree {
  private:
    const int siz;
    vector<T> tree;
    vector<T> lazy;
    vector<bool> marked;

    /** builds the segtree nodes */
    void build(int v, int l, int r, const vector<T> &a) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = max(tree[2 * v], tree[2 * v + 1]);
        }
    }
    
    /** applies lazy update to tree[v], places update at lazy[v], doesn't interact with children */
    void apply(int v, int len, T upd) {
        tree[v] = upd;
        lazy[v] = upd;
        marked[v] = true;       // tell node to update children if needed later
    }

    /** pushes down lazy updates to children of v */
    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        if (!marked[v]) return;     // check if need to update children
        apply(2 * v, m - l + 1, lazy[v]);
        apply(2 * v + 1, r - m, lazy[v]);
        marked[v] = false;          // no longer need to update children
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
            tree[v] = max(tree[2 * v], tree[2 * v + 1]);
        }
    }

    T range_query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) { return INT_MIN; }
        if (ql <= l && r <= qr) { return tree[v]; }
        push_down(v, l, r);
        int m = (l + r) / 2;

        return max(range_query(2 * v, l, m, ql, qr), range_query(2 * v + 1, m + 1, r, ql, qr));
    }

  public:
    LazySegtree(int n) : siz(n), tree(4 * n, INT_MIN), lazy(4 * n), marked(4 * n, false) {}

    LazySegtree(const vector<T> &a) : siz(a.size()), tree(4 * siz), lazy(4 * siz), marked(4 * siz, false) {
        build(1, 0, siz - 1, a);
    }

    /** sets every value on the range [ql, qr] */
    void range_update(int ql, int qr, int upd) { range_update(1, 0, siz - 1, ql, qr, upd); }

    /** @return max of values on [ql, qr] */
    T range_query(int ql, int qr) { return range_query(1, 0, siz - 1, ql, qr); }
};