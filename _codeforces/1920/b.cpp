/*
Problem link: https://codeforces.com/contest/1920/problem/B
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
when does alice want to remove the largest elements?
*/

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vi a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));
    for(int i = 0; i < x; i++) {
        sum -= 2 * a[n - 1 - i];
    }
    int ans = sum;
    // debug(sum);
    for(int i = 0; i < k; i++) {
        int left = n - x - i - 1;
        sum += a[n - 1 - i];
        // ans = max(ans, sum);
        if (left >= 0) sum -= 2*a[left];
        ans = max(ans, sum);
        // if (left < 0) break;
    }
    // ans = max(ans, sum);
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
