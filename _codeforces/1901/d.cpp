/*
Problem link: https://codeforces.com/contest/1901/problem/D
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
https://www.youtube.com/watch?v=9qN9EF-6IcI
*/

void solve() {
    int n; cin >> n;
    vll a(n), pref(n + 1, 0ll), suff(n + 1, 0ll);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        pref[i + 1] = max(pref[i], a[i] + n - (i + 1));
    }
    for(int i = n - 1; i >= 0; i--) {
        suff[i] = max(suff[i + 1], a[i] + i);
    }
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        // cout << a[i] << " " << pref[i] << " " << suff[i + 1] << endl;
        // ans = min(ans, a[i] + pref[i] + suff[i + 1]);
        ans = min(ans, max(max(a[i], pref[i]), suff[i + 1]));
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
