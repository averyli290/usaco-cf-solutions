/*
Problem link: https://codeforces.com/contest/1856/problem/A
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
    vll a(n);
    for(int i = 0;i<n;i++) cin >> a[i];

    ll ans = 0;
    for(int i = n - 1; i > 0; i--) {
        if (a[i - 1] > a[i]) {
            ans = max(a[i - 1], ans);
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
