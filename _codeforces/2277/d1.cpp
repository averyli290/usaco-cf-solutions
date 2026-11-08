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
subtract powers of 2 minus 1

4->1
*/
const ll M =  998244353ll;


void solve() {
    ll l, r; cin >> l >> r;
    ll ans = 0ll;
    for(ll c = l; c <= r; c++) {
        ll curans = 0ll;
        ll totans = LLONG_MAX;
        ll cur = c;
        while (cur != 0) {
            // debug(cur);
            // debug(curans);
            if (cur == 1) {
                totans = min(totans, curans + 1);
                break;
            }
            if (cur == 2) {
                totans = min(totans, curans + 2);
                break;
            }
            if (cur == 3) {
                totans = min(totans, curans + 3);
                break;
            }

            ll over = 2;
            ll ct = 1;
            while(over - 1 <= cur) {
                ct++;
                over <<= 1;
            }
            // debug(over - 1 - cur);
            // debug(ct);
            // debug(curans);
            totans = min(totans, (over - 1) - cur + ct + curans);
            cur -= (over / 2) - 2;
            if (cur == 1) {
                totans = min(totans, ct - 1 + curans);
                break;
            }
            curans += ct + 1;
        }
        // debug(cur);
        // debug(totans);
        ans += totans;
        ans %= M;
    }
    cout << ans % M << endl;
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
