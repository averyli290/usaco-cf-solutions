
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

// typedef pair<int, int> node;
// typedef tree<node, null_type, less<node>,
//             rb_tree_tag, tree_order_statistics_node_update> OM_INT; // ordered_multiset_int

/*
check that the prefix is the same
*/

void solve() {
    string A, B; cin >> A >> B;
    int an = sz(A);
    int bn = sz(B);
    vi a(an), b(bn);
    vi pa(an+1,0), pb(bn+1,0);
    // OM_INT bs;
    vector<vector<int>> dp(an + 1, vector<int>(bn + 1, 0));
    // vector<set<int>> bs(10, set<int>{});
    // vector<set<int>> as(10, set<int>{});
    for(int i = 0;i<an;i++) {
        a[i]=A[i] -'0';
        pa[i + 1] = (a[i] + pa[i]) % 10;
        // as[pa[i + 1]].insert(i);
    }
    for(int i = 0;i<bn;i++) {
        b[i]=B[i] -'0';
        pb[i + 1] = (b[i] + pb[i]) % 10;
        // bs[pb[i + 1]].insert(i);
    }

    if (pa[an] != pb[bn]) {
        cout << -1 << endl;
        return;
    }

    int ans = -1;
    for(int i = 1; i <= an; i++) {
        for(int j = 1; j <= bn; j++) {
            if (pa[i] == pb[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;


    // if (pa[an] != pb[bn]) {
    //     cout << -1 << endl;
    //     return;
    // }

    // int prev = -1;

    // int ans = 0;
    // int last = -1;
    // bool started = false;
    // for(int i = 1; i <= an; i++) {
    //     if (pa[i] == 0 && !started) {
    //         ans++;
    //         last = i;
    //         continue;
    //     }
    //     auto ptr = bs[pa[i]].lower_bound(prev + 1);
    //     if (ptr != bs[pa[i]].end()) {
    //         last = i;
    //         int idx = *ptr;
    //         ans++;
    //         prev = idx;
    //         started = true;
    //     }
    // }
    // // debug(last);
    // // debug(pa[an] - pa[an - 1]);
    // if (last != an && pa[an] - pa[last ] != 0) cout << -1 << endl;
    // else cout << ans << endl;

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
