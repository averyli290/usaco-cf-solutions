
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
for each r, i want to find the largest l to minimize the range size
*/

void solve() {
    int n; cin >> n;
    multiset<ll> l,r;
    vll c(n);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        l.insert(x);
    }
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        r.insert(x);
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<pll> intervals;
    for(ll right : r) {
        auto leftptr = l.upper_bound(right);
        leftptr--;
        intervals.push_back({*leftptr, right});
        l.erase(leftptr);
    }
    ll ans = 0LL;
    sort(all(intervals), [&](pll a, pll b) { return (a.second - a.first) < (b.second - b.first); });
    sort(all(c),[](ll a, ll b) {return b < a;});
    for(int i = n - 1; i >= 0; i--) {
        ans += c[i] * (intervals[i].second - intervals[i].first);
    }
    cout << ans << endl;

    /*
    [0, 8] 
    [1, 9]
    0, 5
    */
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