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


void solve() {
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (a > b) {
        if ((a ^ 1) == b) {
            cout << y << endl;
            return;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    int ans = 0;
    while (a < b) {
        if (a % 2 == 0) {
            if (x < y) {
            a += 1;
            ans += x;

            } else {
            a ^= 1;
            ans += y;

            }
        } else {
            a += 1;
            ans += x;
        }
    }
    if (a == b) {
        cout << ans << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
