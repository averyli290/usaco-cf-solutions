/*
Problem link: https://codeforces.com/contest/2180/problem/D
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
    int n; cin >> n;
    vll x(n);
    vll maxval(n);
    for(int i = 0;i < n;i++) {
        cin >> x[i];
    }
    for(int i = 0;i < n;i++) {
        ll v1 = LLONG_MAX;
        ll v2 = LLONG_MAX;
        if (i > 0) v1 = x[i] - x[i - 1];
        if (i < n - 1) v2 = x[i + 1] - x[i];
        maxval[i] = min(v1, v2);
    }
    int ans = 0;
    vll minval(n, 0ll);
    for(int i = 0; i < n - 1; i++) {
        ll gap = x[i + 1] - x[i];
        // debug(i);
        // debug(gap);
        // debug(minval[i]);
        // debug(maxval[i]);
        // debug(minval[i + 1]);
        // debug(maxval[i + 1]);
        // debug(gap);
        if (maxval[i] + maxval[i + 1] < gap || minval[i] + minval[i + 1] >= gap) {
            // debug(minval[i]);
            // debug(maxval[i]);
            continue;
        } else {
            minval[i + 1] = max(minval[i + 1], gap - maxval[i]);
            maxval[i + 1] = min(maxval[i + 1], gap - minval[i]);
            ans++;
        }
    }
    cout << ans << endl;
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
