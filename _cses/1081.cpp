/*
Problem link: https://cses.fi/problemset/task/1081/
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
    int n; cin >> n;
    vi ct(1e6 + 1, 0ll);
    int ans = 1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        for(int d = 1; d * d <= x; d++) {
            if(x % d == 0) {
                ct[d]++;
                if (ct[d] > 1) ans = max(ans, d);
                if (d * d != x) {
                    ct[x / d]++;
                    if (ct[x/d] > 1) ans = max(ans, x / d);
                }
            }
        }
    }
    cout << ans << endl;
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
