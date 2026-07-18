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


void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    vi b(n);
    for(int i = 0; i< n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {x, y};
        b[i] = y;
    }
    sort(all(a));
    sort(all(b));
    ll ans = 0ll;
    int r = 0;
    for(int i = 0; i < n; i++) {
        // check ppl after or eq
        int after = lower_bound(all(b), a[i].second) -  b.begin();
        b.erase(b.begin() + after);
        ans += (ll) after;
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
