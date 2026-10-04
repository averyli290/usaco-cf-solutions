/*
Problem link: https://codeforces.com/problemset/problem/2007/C
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
    int n; cin >> n;
    ll a, b; cin >> a >> b;
    vll c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(all(c));
    ll g = gcd(a,b);
    for(int i = 0; i < n; i++) {
        c[i] %= g;
    }
    sort(all(c));
    ll ans = c[n - 1] - c[0];
    for(int i = 1; i < n; i++) {
        ans = min(ans, max(c[n - 1] - c[i], c[i - 1] + g - c[i]));
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