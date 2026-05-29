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
if any a[i] <= k, the shared value is >= k
after (a[i] + k), one of the split terms >= k

what if all a[i] >= k?

k = 0

3x -> 2x, x -> x, x, x

take smallest, check that each of the others are multiple of smallest

(x - k) + k = x
x = y + z


*/

void solve() {
    ll n; cin >> n >> k;
    vll a(n);
    // ll totsum = 0;
    for(int i = 0; i < (int) n; i++) {
        cin >> a[i];
        // totsum += a[i];
    }
    
    sort(all(a));
    

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
