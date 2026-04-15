#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    LazySegtree(const vector<T> &a) : siz(a.size()), tree(4 * siz), lazy(4 * siz) {
        build(1, 0, siz - 1, a);
    }

    /** adds to every value on the range [ql, qr] */
    void range_update(int ql, int qr, int upd) { range_update(1, 0, siz - 1, ql, qr, upd); }

    /** @return sum of values on [ql, qr] */
    T range_query(int ql, int qr) { return range_query(1, 0, siz - 1, ql, qr); }
};

// int main() {
//     int test_num;
//     cin >> test_num;
//     for (int t = 0; t < test_num; t++) {
//         int n, q;
//         cin >> n >> q;
// 
//         LazySegtree<ll> st(n);
//         for (int i = 0; i < q; i++) {
//             int type;
//             cin >> type;
// 
//             if (type == 0) {
//                 int p, q, val;
//                 cin >> p >> q >> val;
//                 p--, q--;
//                 st.range_update(p, q, val);
//             } else {
//                 int p, q;
//                 cin >> p >> q;
//                 p--, q--;
//                 cout << st.range_query(p, q) << '\n';
//             }
//         }
//     }
// }