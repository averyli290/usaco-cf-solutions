/*
Problem link: https://codeforces.com/contest/1986/problem/G1
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
if pi % i, req[i] = pi / gcd(i, pi), sup[i] = i / gcd(i, pi)

reqmap[divisors(req[i])]++;
supmap[divisors([i])]++;

*/

void solve() {
    ll n; cin >> n;
    vll a(n + 1);
    ll onect = 0ll;
    for(ll i = 0ll; i < n; i++) {
        cin >> a[i + 1];
        if ((a[i + 1] % (i + 1)) == 0) onect++;
    }
    // ll ans = (onect - 1) * onect / 2;
    ll ans = 0ll;
    for(ll i = 1ll; i <= n; i++) {
        // if (a[i] % i != 0) {
        // }
            ll need = a[i] / gcd(a[i], i);
            // debug(i);
            // debug(need);
            for(ll j = i / need * need; j <= n; j+=need) {
                if ((j > i) && (a[i] * a[j]) % (i * j) == 0) {
                    // cout << i << " " << j << endl;
                    ans++;
                }
            }
        // for(int j = i + 1; (j * i <= n * (n - 1)) && (j <= n); j++) {
        //     ll prod = ((ll) i) * j;
        //     if((a[i] * a[j]) % prod == 0) {
        //         cout << i << " " << j << endl;
        //         ans++;
        //     }
        // }
    }
    // cout << (n * (n - 1)) / 2 - ans << endl;
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
