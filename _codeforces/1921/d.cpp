/*
Problem link: https://codeforces.com/contest/1921/problem/D
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
9 10 6 3 7
5 9 2 3 9

3 6 7 9 10
2 3 5 9 9
6 + 4 + 4 + 4 + 1

8 + 6 + 2 + 3 + 6
14 + 11 = 25
*/


void solve() {
    int n, m; cin >> n >> m;
    vll a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll ans = 0ll;
    int right = m - (m - n);
    for(int i = 0; i < right; i++) {
        ans += abs(b[right - 1 - i] - a[i]);
    }
    for(int i = 0; i < m - n; i++) {
        int left = right - (m - n);
        ans -= abs(b[left] - a[i])
    }
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
