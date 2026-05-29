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
choose an interval of length k to build off of
each value can only take (x % p) or (x % q) % p
then, for every value outside of the interval (can build outwards by 1 element on edge)
if we want (x % p) we take the entire interval plus that one on the edge mod p
and if we can (x % q) % p we take the entire interval plus that one on the edge mod q then mod p
and the operations dont affect the existing values because q, p >= p
then, all other elements are min(p, q) outside of first interval
*/

void solve() {
    int n, k; cin >> n >> k;
    ll p, q; cin >> p >> q;
    if (p > q) swap(p, q);
    vll pref1(n + 1, 0LL);
    vll pref2(n + 1, 0LL);
    vll pref3(n + 1, 0LL);
    vll pref4(n + 1, 0LL);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        pref1[i+1] = pref1[i] + (x % p);
        pref2[i+1] = pref2[i] + (x % q);
        pref3[i+1] = pref3[i] + ((x % q) % p);
        pref4[i+1] = pref4[i] + min(x % p, (x % q) % p);
    }

    ll ans = LLONG_MAX;
    for(int i = k; i <= n; i++) {
        ll mins = pref4[n] - pref4[i] + pref4[i - k];
        ans = min(ans, mins + min(pref1[i] - pref1[i - k], pref3[i] - pref3[i - k]));
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
