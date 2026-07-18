/*
Problem link:
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
const long long M = 11092019;


void solve() {
    string s; cin >> s;
    int n = sz(s);
    vll ct(26, 0ll);
    for(int i = 0; i < n; i++) {
        ct[s[i] - 'a']++;
    }
    ll ans = 1ll;
    for(ll x : ct) {
        ans *= (x + 1);
        ans %= M;
    }
    cout << ans << endl;
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
