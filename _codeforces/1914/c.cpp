/*
Problem link: https://codeforces.com/contest/1914/problem/C
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
    int n, k; cin >> n >> k;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    int cur = 0;
    int maxb = 0;
    for(int i = 0; i < k && i < n; i++) {
        cur += a[i];
        maxb = max(maxb, b[i]);
        ans = max(ans, cur + maxb * (k - i - 1));
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
