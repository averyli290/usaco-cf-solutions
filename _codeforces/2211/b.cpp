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
    int x, y; cin >> x >> y;
    int diff = max(x, y) - min(x, y);
    int ans = 0;
    if (diff == 0) ans = 1;
    for(int i = 1; i * i <= diff; i++) {
        if (i * i == diff) ans++;
        else if (diff % i == 0) ans += 2;
    }
    cout << ans << endl;

    for(int i = 0; i < x; i++) cout << 1 << " ";
    for(int i = 0; i < y; i++) cout << -1 << " ";
    cout << endl;

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
