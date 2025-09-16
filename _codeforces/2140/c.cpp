/*
Problem link: https://codeforces.com/contest/2140/problem/C
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
bob should end on his turn no matter what
alice can undo bob's move and get more score every time
find best move for alice
*/

void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0LL;
    for(int i = 0; i < n; i++) {
        if (i % 2 == 0) ans += a[i];
        else ans -= a[i];
    }

    // i - j = 0 (mod 2)
    if (n > 2) ans = max(ans, ans + (n - 1) / 2 * 2);
    // cout <<"val: "<< (n+1)/2 * 2 << endl;
    // subtract 2 * even, add 2 * odd

    // uhh just use prefix and factor in index there
    ll maxeven = -INF / 2; // even
    ll minodd = INF / 2; // odd
    ll start = ans;
    ll newans = ans;

    for(int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            newans = max(newans, start - minodd - 2 * a[i] + i);
            maxeven = max(maxeven, -i + 2 * a[i]);
        } else {
            newans = max(newans, start + 2 * a[i] - maxeven + i);
            minodd = min(minodd, i - 2 * a[i]);

        }
    }
    cout << newans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
