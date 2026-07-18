/*
Problem link: https://codeforces.com/problemset/problem/1722/E
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

// template <typename T> class BIT2D {
//   private:
//     const int n, m;
//     vector<vector<T>> bit;

//   public:
//     BIT2D(int n, int m) : n(n), m(m), bit(n + 1, vector<T>(m + 1)) {}

//     /** adds val to the point (r, c) */
//     void add(int r, int c, T val) {
//         r++, c++;
//         for (; r <= n; r += r & -r) {
//             for (int i = c; i <= m; i += i & -i) { bit[r][i] += val; }
//         }
//     }

//     /** @returns sum of points with row in [0, r] and column in [0, c] */
//     T rect_sum(int r, int c) {
//         r++, c++;
//         T sum = 0;
//         for (; r > 0; r -= r & -r) {
//             for (int i = c; i > 0; i -= i & -i) { sum += bit[r][i]; }
//         }
//         return sum;
//     }

//     /** @returns sum of points with row in [r1, r2] and column in [c1, c2] */
//     T rect_sum(int r1, int c1, int r2, int c2) {
//         return rect_sum(r2, c2) - rect_sum(r2, c1 - 1) - rect_sum(r1 - 1, c2) +
//                rect_sum(r1 - 1, c1 - 1);
//     }
// };


void solve() {
    int n, q; cin >> n >> q;
    vector<vll> B(1001, vll(1001, 0ll));
    vector<vll> pref(1002, vll(1002, 0ll));
    for(int i = 0; i < n; i++) {
        ll h, w;
        cin >> h >> w;
        B[h][w] += h * w;
    }
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i-1][j-1] + B[i][j];
        }
    }
    while(q--) {
        ll h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;
        cout << pref[h2 - 1][w2 - 1] - pref[h2 - 1][w1] - pref[h1][w2 - 1] + pref[h1][w1] << endl;
        // cout << B.rect_sum(h1 + 1, w1 + 1, h2 - 1, w2 - 1) << endl;
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
