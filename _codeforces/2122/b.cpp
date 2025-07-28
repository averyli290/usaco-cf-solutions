/*
Problem link:
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;

/*
ignore ones that match

put 1's first
for too many 1's, multiply by 2 times diff
*/

void solve() {
    int n; cin >> n;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c) {
            ans += a - c;
        }
        if (b > d) {
            ans += b - d;
            ans += max(a - c, 0);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }

}
