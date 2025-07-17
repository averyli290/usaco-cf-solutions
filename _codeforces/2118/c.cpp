/*
Problem link: https://codeforces.com/contest/2118/problem/C
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
    ll n, k; cin >> n >> k;
    vll a(n); vll b;
    ll ans = 0;
    for(ll i=0;i<n;i++) {
        cin >> a[i];
        for(int j = 0; j <= 62; j++) {
            if ((a[i] >> j) % 2 == 0) {
                b.push_back(1LL << j);
            } else {
                ans++;
            }
        }
    }
    sort(all(b));
    for(int i=0;i<sz(b);i++) {
        if (k >= b[i]) {
            ans++;
            k -= b[i];
        } else {
            break;
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
