/*
Problem link:
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

/*
r - l
l is leftmost
r is rightmost

r - (r + l) = r - l, redistribute over all segments to re-pair
*/

void solve() {
    int n; cin >> n;
    ll ans = 0ll;
    vector<pll> a(n);
    vector<pll> b(n);
    ll odd = 0ll;
    for(int i = 0; i < n; i++) {
        ll l, r; cin >> l >> r;
        a[i] = {l, r};
        b[i] = {r + l, i};
        ans += r;
        ans += r - l + 1;
    }

    sort(all(b));
    debug(ans);
    for(int i = 0; i < (n + 1) / 2; i++) ans -= b[i].first;
    for(int i = (n + 1)/2; i < n; i++) if (n % 2 == 1) odd = max(odd, a[b[i].second].second - a[b[i].second].first + 1);
    cout << ans + odd << endl;

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
