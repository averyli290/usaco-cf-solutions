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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lo = a[0];
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if (a[i] > a[i - 1] + 1) {
            lo = a[i];
            ans++;
        } else if (a[i] <= lo) {
            lo = a[i];
            ans++;
        }
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
