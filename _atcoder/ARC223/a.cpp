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
a,b,c,d
a+b % k == 0 
b+c % k == 0 
a+c % k == 0 
c+d % k == 0
b+d % k == 0

a-c % k == 0
(a-c) + (c+d) % k == 0 => a+d % k == 0

a,b,c,d
a,c,b,d

*/

void solve() {
    ll n, W; cin >> n >> W;
    vll v(n), w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    vll prefw(n + 1, 0ll), prefv(n + 1, 0ll);
    for(int i = 0; i < n; i++) {
        prefw[i + 1] = prefw[i] + w[i];
        prefv[i + 1] = prefv[i] + v[i];
    }

    ll curans = 0ll;
    ll ans = 0ll;
    for(int i = n - 1; i >= 0; i--) {
        if (W - w[i] >= 0) {
            ll ans1 = curans + prefv[i];    // dont take current

            // take current
            W -= w[i];
            curans += v[i];

            // update ans
            ans = max(ans, max(curans, ans1));
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
