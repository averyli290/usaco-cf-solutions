/*
Problem link: https://codeforces.com/contest/2244/problem/D
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
5 3
-1 2 -3 4 -5
1 5 3

1 -2 3 -4 5


*/

void solve() {
    int n, m; cin >> n >> m;
    vll a(n);
    vi ct(n, 0);
    vi b(m);
    for(int i = 0; i< n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i< m; i++) {
        cin >> b[i];
    }
    sort(all(b));

    int cur = m - 1;
    for(int i = n - 1; i >= 0; i--) {
        while (cur >= 0 && b[cur] >= i + 1) {
            cur--;
        }
        ct[i] = m - cur - 1;
    }
    vll temps(m + 1, 0ll);
    for(int i = 0; i < n; i++) {
        temps[ct[i]] += a[i];
    }
    ll ans = 0ll;
    for(int i = 1; i<m + 1; i++) {
        // debug(temps[i]);
        ans += abs(temps[i]);
    }
    ans += temps[0];
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

