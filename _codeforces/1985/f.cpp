/*
Problem link: https://codeforces.com/problemset/problem/1985/F
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
    ll h, n; cin >> h >> n;
    vll a(n), c(n);
    ll s = 0ll;
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for(int i = 0 ;i < n; i++) {
        cin >> c[i];
    }
    if (s >= h) {
        cout << 1 << endl;
        return;
    }

    function<bool(ll)> check = [&] (ll t) {
        ll tot = 0ll;
        for(int i = 0; i < n; i++) {
            tot += a[i] * ((t - 1ll) / c[i] + 1ll);
        }
        return tot >= h; 
    };
    ll lo = 1ll;
    ll hi = (max(*max_element(all(c)), 0ll)) * h;
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
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
