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
    int n, m; cin >> n >> m;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    reverse(all(a));
    priority_queue<ll> pq;
    for(int i = 0; i < m; i++) {
        pq.push(0ll);
    }
    for(int i = 0; i < n; i++) {
        ll cur = pq.top();
        pq.pop();
        cur -= a[i];
        pq.push(cur);
    }
    ll ans = 0ll;
    while(!pq.empty()) {
        ans -= pq.top();
        pq.pop();
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
