/*
Problem link: https://cses.fi/problemset/task/1082/
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
const long long M = 1e9+7;


void solve() {
    ll n; cin >> n;
    ll tot = 0ll;
    ll prev = 0ll;
    for(ll i = 1; (i - 1) * (i - 1) <= n; i++) {
        // debug(i);
        ll top = n / i * i;
        // debug(top);
        ll ct = n / i;
        // tot += (top + i) * ct / 2;
        tot += i * ct;
        debug(i);
        debug(ct);
        tot %= M;
        if (i * i != n) {
            // debug(n / i);
            ll other = n / i;
            if (other * other > n) {
                debug(other);
                prev = other;
                ct = n / other;
                tot += ct * other;
            }

            // top = n / (n / i) * i;
            // ct = n / (n / i);
            // tot += (top + (n / i)) * ct / 2;
            // top %= M;
        }
        debug(tot);
    }
    cout << tot << endl;
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
