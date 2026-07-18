/*
Problem link: https://codeforces.com/contest/1920/problem/A
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
    vector<pii> a(n);
    int minval = -INT_MAX;
    int maxval = INT_MAX;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {x, y};
        if (x == 1) {
            minval = max(minval, y);
        }
        if (x == 2) {
            maxval = min(maxval, y);
        }
    }
    // debug(minval);
    // debug(maxval);
    int ans = maxval - minval + 1;
    for(int i = 0; i < n; i++) {
        if (a[i].first == 3 && a[i].second <= maxval && a[i].second >= minval) ans--;
    }
    cout << max(0, ans) << endl;
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
