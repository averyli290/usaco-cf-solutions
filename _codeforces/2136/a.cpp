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
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (a < b) {
        swap(a, b);
        swap(c, d);
    }
    if (a > 2 * (b + 1)) {
        cout << "NO" << endl;
        return;
    }
    c -= a;
    d -= b;
    if (c < d) {
        swap(c, d);
    }
    if (c > 2 * (d + 1)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
