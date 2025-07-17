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
    ll n; cin >> n;
    int len = 0;
    int x = n;
    while (x > 0) {
        x /= 10;
        len++;
    }
    int cur = 10;
    // amount of time for first digit
    int ans = (n + 10 - 7) % 10;
    for(int i = 1; i < len; i++) {
        int a = n / cur % 10;
        ans = min(ans, (17 - a) % 10);
        cur *= 10;
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
