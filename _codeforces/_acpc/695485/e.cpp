/*
Problem link: https://codeforces.com/group/mU33rA0Qul/contest/695485/problem/E
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
const ll M = 1E9+7;


void solve() {
    ll n; cin >> n;
    vll dp(n + 1, 0ll);
    dp[0] = 1ll;
    for(ll i = 0; i < n; i++) {
        ll v = (ll) i;
        ll cur = 1ll;
        while(v + cur <= n) {
            dp[v + cur] = (dp[v + cur] + dp[v]) % M;
            cur <<= 1ll;
        }
    }
    cout << (dp[n] * 2) % M << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
