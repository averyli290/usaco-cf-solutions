/*
Problem link: https://codeforces.com/contest/2245/problem/B
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

1 3 1

1 1 3

3 - 2 = 1

*/

void solve() {
    ll n, c; cin >> n >> c;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    ll idx = 0ll;
    for(ll i = 0; i < n / 2; i++) {
        if (a[i] >= c) break;
        idx++;
    }
    ll ans = 0ll;
    while(idx < n) {
        ans += a[idx] - c;
        idx++;
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
