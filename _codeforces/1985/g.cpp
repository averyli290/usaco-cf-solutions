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
const long long M = 1e9+7;


long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll l, r, k; cin >> l >> r >> k;
    if (k < 10) {
        ll ctr = 0ll;
        while (ctr * k < 10) ctr++;
        // ctr--;
        // debug(ctr);
        ll ans = (binpow(ctr, r, M) - 1);
        if (l > 0) {
            ans -= binpow(ctr, l, M) - 1;
        }

        cout << (ans + 2 * M) % M<< endl;

    } else {
        cout << 0 << endl;
    }
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
