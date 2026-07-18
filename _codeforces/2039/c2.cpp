/*
Problem link: https://codeforces.com/contest/2039/problem/C2
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
1: (x ^ y) % x = 0
x ^ y <= x + y
2: 
*/


void solve() {
    ll x, m; cin >> x >> m;

    ll ans = (m - x) / x;   // case 1
    ll other = ((m - x - 1) / x + 1) * x;
    if ((other ^ x) <= m) ans++;
    other = (m - x) / x + x;
    if ((other ^ x) <= m) ans++;
    debug(ans);

    ll ystart = 1ll;
    while(ystart <= x) {
        ystart <<= 1;
    }
    // debug(ystart);
    ll yend = ystart;

    for(ll y = 1; y <= min(m, yend - 1); y++) {
        ll z = x ^ y;
        if (z % y == 0 || z % x == 0) {
            ans++;
        }
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
