/*
Problem link: https://atcoder.jp/contests/abc463/tasks/abc463_d
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


void solve() {
    int n, k; cin >> n >> k;
    vector<pii> a(n);
    for(int i = 0;i < n ;i++) {
        int l, r; cin >> l >> r;
        a[i] = {r, l};
    }

    sort(all(a));

    function<bool(int)> check = [&] (int gap) {
        int last_right = -(gap + 1);
        int taken = 0;
        for(int i = 0; i < n; i++) {
            if (last_right + gap <= a[i].second && last_right != a[i].second) {
                // debug(i);
                // debug(last_right);
                // debug(a[i].second);
                last_right = a[i].first;
                taken++;
            }
        }
        return taken >= k;
    };

    int lo = -1;
    int hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        // debug(mid);
        if (check(mid)) {
            lo = mid;
        } else  {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
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
