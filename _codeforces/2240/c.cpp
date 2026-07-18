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

/*
1 move game?
*/

void solve() {
    int n; cin >> n;
    vll a(n);
    ll meep = 0ll;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        meep ^= a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    if (meep == 0ll) {
        cout << 1 << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        ll cur = meep ^ a[i];   // make everything else except for this num 0
        if (cur <= a[i]) ans++;     // can do? if cur <= a[i]
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
