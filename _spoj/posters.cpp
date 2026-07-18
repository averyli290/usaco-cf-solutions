/*
Problem link: https://www.spoj.com/problems/POSTERS/
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
    
    /** applies lazy update to tree[v], places update at lazy[v] */
    void apply(int v, int len, T upd) {
        tree[v] = upd;
        lazy[v] = upd;
        marked[v] = true;
    }

    /** pushes down lazy updates to children of v */
    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        if (!marked[v]) return;
        apply(2 * v, m - l + 1, lazy[v]);
        apply(2 * v + 1, r - m, lazy[v]);
        marked[v] = false;
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

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    // coordinate compression
    vi ranges(2 * n);
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        ranges[2 * i] = l;
        ranges[2 * i + 1] = r;
    }
    vector<pii> pairs(2 * n);
    for(int i = 0; i < 2 * n; i++) pairs[i] = {ranges[i], i};   // store index in second of pair
    sort(all(pairs));
    int ctr = 0;
    for(int i = 0; i < 2 * n; i++) {
        if (i > 0 && pairs[i - 1].first != pairs[i].first) ctr++;
        ranges[pairs[i].second] = ctr; // compress targ index (pairs[i].second)

    }

    LazySegtree<int> ls(ctr + 1);

    for(int i = 0; i < n; i++) {
        int l = ranges[2 * i];
        int r = ranges[2 * i + 1];
        ls.range_update(l, r, i);
    }
    set<int> s;
    for(int i = 0; i < ctr + 1; i++) s.insert(ls.range_query(i, i));
    cout << sz(s) << endl;
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
