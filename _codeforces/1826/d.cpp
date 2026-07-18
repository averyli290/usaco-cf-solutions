/*
Problem link: https://codeforces.com/contest/1826/problem/D
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
for 3 pointer questions:
ask if we can iterate across all possibilities for middle element
and then choose the left and right quickly from there
*/

void solve() {
    int n; cin >> n;
    vll a(n, 0ll);
    vll pref(n + 2, LLONG_MIN);
    vll suff(n + 2, LLONG_MIN);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n; i++) {
        pref[i] = max(pref[i - 1], a[i - 1] + i);
    }
    for(int i = n;i >= 1; i--) {
        suff[i] = max(suff[i + 1], a[i - 1] - i);
    }
    ll ans = 0ll;
    for(int i = 2; i <= n - 1; i++) {
        // debug(i);
        // debug(pref[i - 1]);
        // debug(a[i - 1]);
        // debug(suff[i + 1]);
        ans = max(ans, pref[i - 1] + a[i - 1] + suff[i + 1]);
        // debug(ans);
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
