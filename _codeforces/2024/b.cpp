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
a - x = (b - a + 1) / 2;

a - x = b - 2x
a - b = - 3x
3x = b - a
*/

void solve() {
    int n;cin >> n;
    ll k; cin >> k;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.push_back(0ll);
    sort(all(a));
    ll cur = 0ll;
    ll ans = 0ll;
    ll prev = 0ll;
    for(int i = 1; i <= n; i++) {
        if (cur + ((a[i] - a[i - 1]) * (n + 1 - i)) >= k) {
            cout << ans + k - cur << endl;
            return;
        }
        cur += ((a[i] - a[i - 1]) * (n + 1 - i));
        ans += ((a[i] - a[i - 1]) * (n + 1 - i)) + 1;
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
