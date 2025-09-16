/*
Problem link: https://codeforces.com/contest/2134/problem/C
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
    int n; cin >> n;
    vll a(n);
    for(int i = 0;i <n;i++) cin >> a[i];
    if (n % 2 == 0) a.push_back(0);
    ll ans = 0;
    for(int i = 1; i < n; i += 2) {
        if (a[i - 1] > a[i]) {
            ans += a[i - 1] - a[i];
            a[i - 1] = a[i];
        }
        if (a[i + 1] > a[i]) {
            ans += a[i + 1] - a[i];
            a[i + 1] = a[i];
        }
        ll diff = a[i + 1] + a[i - 1] - a[i];
        if (diff > 0) {
            // sub from right first
            ll to_sub = min(a[i + 1], diff);
            ll leftover = diff - to_sub;
            a[i + 1] -= to_sub;
            ans += diff;
        }
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
