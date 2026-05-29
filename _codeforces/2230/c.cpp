/*
Problem link: https://codeforces.com/contest/2230/problem/C
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

aabbcc

*/


void solve() {
    int n; cin >> n;
    vll a(n);
    ll gtct = 0LL;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= 2) gtct++;
    }

    // sort(all(a));

    if (gtct == 0) {
        cout << 0 << endl;
        return;
    } else if (gtct == 1) {
        ll ans = 0LL;
        ll other = 0LL;
        ll allow = 0LL;
        for(int i = 0; i < n; i++) {
            if (a[i] >= 2) {
                ans += a[i];
                allow += a[i] / 2;
            } else {
                other += 1;
            }
        }
        ans += min(other, allow);
        if (ans >= 3) cout << ans << endl;
        else cout << 0 << endl;
    } else {
        ll ans = 0LL;
        ll other = 0LL;
        ll allow = 0LL;
        for(int i = 0; i < n; i++) {
            if (a[i] >= 2) {
                ans += a[i];
                allow += a[i] / 2 - 1;
            } else {
                other += 1;
            }
        }
        ans += min(other, allow);
        if (ans >= 3) cout << ans << endl;
        else cout << 0 << endl;
    }

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
