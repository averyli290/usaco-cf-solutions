/*
Problem link: https://codeforces.com/contest/2238/problem/B
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
a and c must be multiples of b
doesn't matter what multiples
*/

void solve() {
    int n; cin >> n;
    ll ans = 0ll;
    for(int i = 1; i <= n; i++) {
        ll ct = (ll) (n / i);
        ans += ct * ct;
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
