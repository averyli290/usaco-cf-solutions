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

/*
tot[idx] = # of total free points so far
dp[x] = max score so far if put x points into strength

if attribute check
calc attribute score, check if should increase for each x
nextdp[x] = dp[x] + 

if upgrade point
nextdp[x + 1] = max(dp[x], dp[x + 1]);
nextdp[0] = dp[0];

dp = nextdp

*/


template <typename T> class LazySegtree {
  private:
    int siz;
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
    
    /** applies lazy update to tree[v], places update at lazy[v] */
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

    T range_query_sum(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) { return 0; }             // CHECK
        if (ql <= l && r <= qr) { return tree[v]; }     // CHECK
        push_down(v, l, r);
        int m = (l + r) / 2;

        // CHECK
        return range_query_sum(2 * v, l, m, ql, qr) + range_query_sum(2 * v + 1, m + 1, r, ql, qr);
    }

    T range_query_max(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) { return 0; }             // CHECK
        if (ql <= l && r <= qr) { return tree[v]; }     // CHECK
        push_down(v, l, r);
        int m = (l + r) / 2;

        // CHECK
        return max(range_query_max(2 * v, l, m, ql, qr), range_query_max(2 * v + 1, m + 1, r, ql, qr));
    }

  public:
    LazySegtree(int n) : siz(n), tree(4 * n), lazy(4 * n) {}

    LazySegtree(const vector<T> &a) : siz(a.size()), tree(4 * siz), lazy(4 * siz) {
        build(1, 0, siz - 1, a);
    }

    /** adds to every value on the range [ql, qr] */
    void range_update(int ql, int qr, int upd) { range_update(1, 0, siz - 1, ql, qr, upd); }

    /** @return sum of values on [ql, qr] */
    T range_query_sum(int ql, int qr) { return range_query_sum(1, 0, siz - 1, ql, qr); }
    /** @return sum of values on [ql, qr] */
    T range_query_max(int ql, int qr) { return range_query_max(1, 0, siz - 1, ql, qr); }
};


void solve() {
    int n, m; cin >> n >> m;
    LazySegtree<int> dp(m + 2);
    int tot_points = 0;
    for(int i = 0; i < n; i++) {
        vi next(m + 2, 0);
        int x; cin >> x;
        // debug(tot_points);
        // debug(x);
        if (x == 0) {
            tot_points++;
            for(int j = 0; j <= tot_points; j++) {
                next[j + 1] = dp.range_query_max(j+2, j+1);
            }
            next[1] = dp.range_query_max(1,1);
            LazySegtree<int> temp(next);
            dp = temp;
        } else if (x > 0) {
            if(tot_points >= x) dp.range_update(x + 1, tot_points + 1, 1);
            // for(int j = 0; j <= tot_points; j++) {
            //     // if tot_points >= x, range update between [x, tot_points] by 1
            //     // int cur_int = tot_points - j;
            //     // next[j] = dp[j] + (cur_int >= x ? 1 : 0);
            // }
        } else {
            if(tot_points >= abs(x)) dp.range_update(0 + 1, tot_points + x + 1, 1);
            // for(int j = 0; j <= tot_points; j++) {
            //     // if tot_points >= x, range update between [0, tot_points - x] by 1
            //     // int cur_str = j;
            //     // next[j] = dp[j] + (cur_str >= -x ? 1 : 0);
            // }
        }
        // cout << dp.range_query_max(1, m + 1) << endl;
    }
    cout << dp.range_query_max(1, m + 1) << endl;
    // int ans = 0;

    // for(int m : dp) ans = max(m, ans);
    // cout << ans << endl;
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