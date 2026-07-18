/*
Problem link: https://codeforces.com/contest/2205/problem/B
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
    ll n; cin >> n;
    ll ans = 1ll;
    for(ll d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            ans *= d;
            while (n % d == 0) n /= d;
        }
    }
    if (n > 1) ans *= n;
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
