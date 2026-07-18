/*
Problem link: https://codeforces.com/contest/2240/problem/D
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
give gift to person i
+ 2d * a[i], -a[j] for each person who has a gift in that range, -a[j] for each person who does NOT have gift in that range
=2d * a[j] for j in range regardless if that person had gift or not
*/

void solve() {
    ll n, d; cin >> n >> d;
    ll ans = 0ll;
    vll a(n), pref(3 * n + 1, 0ll);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 2 * n; i++) {
        pref[i + 1] = pref[i] + a[i % n];
    }

    for(int i = 1; i <= n; i++) {
        ll stanley = 2 * d * a[i - 1];
        ll lidx = i - d;
        ll ridx = i + d;
        if (lidx < 1) {
            lidx += n;
            ridx += n;
        }
        ll aadi = pref[ridx] - pref[lidx - 1] - a[i - 1];
        // debug(i);
        // debug(ridx);
        // debug(lidx);
        // debug(stanley - aadi);
        ans += max(0ll, stanley - aadi);
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
