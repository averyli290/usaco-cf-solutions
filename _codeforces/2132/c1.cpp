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


void solve() {
    ll n; cin >> n;
    ll cur = 1ll;
    vll a;
    while(cur <= n) {
        cur *= 3;
        a.push_back(0ll);
    }
    int ctr = sz(a);
    ll n2 = n;
    ll tot = 0;
    while (n2 > 0) {
        if (cur <= n2) {
            a[ctr] = n2 / cur;
            n2 %= cur;
            tot += a[ctr];
        }
        ctr--;
        cur /= 3;
    }

    // if (tot > k) {
    //     cout << -1 << endl;
    //     return;
    // }
    // for(int i = sz(a) - 1; i > 0; i--){
    //     if (a[i] > 0) {
    //         ll can_conv = (k - tot) / 2;
    //         if (can_conv == 0) break;
    //         else {
    //             ll conv = min(can_conv, a[i]);
    //             a[i] -= conv;
    //             a[i - 1] += 3 * conv;
    //             tot += 2 * conv;
    //         }
    //     }
    // }

    ll ans = 0;
    for(int i = 1; i <= sz(a); i++) {
        // cout << a[i - 1] << " ";
        ans += a[i - 1] * (pow(3, i) + (i - 1) * pow(3, i - 2));
    }
    // cout << endl;
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
