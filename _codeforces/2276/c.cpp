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
*/

void solve() {
    int n, k; cin >> n >> k;
    map<ll, ll> mp;
    ll cur = 0ll;
    ll ans = 0ll;
    queue<ll> q;
    q.push(0ll);
    for(int i = 0 ; i < n ;i++) {
        ll x; cin >> x;
        cur += x;
        cur %= k;
        ans += mp[cur];
        // debug(ans);
        q.push(cur);
        if (i >= k - 1) {
            ll upd = q.front();
            q.pop();
            mp[upd]++;
        }
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
