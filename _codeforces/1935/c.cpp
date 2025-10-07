/*
Problem link:
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
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;

/*
given set of messages, can rearrange them to minimize the b_i's by sorting

then, if not jumping between elements in sorted, can sort and then check lefts and rights
*/

void solve() {
    int n; cin >> n;
    ll k; cin >> k;
    vector<pair<ll, ll>> c(n);
    // vll a(n), b(n);
    // for(int i = 0; i < n; i++) cin >> a[i];
    // for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        c[i] = {b,a};
    }
    sort(all(c));
    for(int i = 0; i < n; i++) {
        cout << c[i].first << " " << c[i].second << endl;
    }
    /*
    2 4
    1 5
    2 3

    3 2
    4 2
    5 1
    */
    cout << endl;
    ll ans = 0;
    vector<bool> taken(n, false);
    for(int i = 0; i < n; i++) {
        // debug(i);
        // ll cur = c[i].second;
        // debug(cur);
        // if (cur <= k) ans = max(ans, 1LL);
        // for(int j = i + 1; j < n; j++) {
        //     cur += abs(c[j].first - c[j - 1].first) + c[j].second;
        //     if (cur <= k) ans = max(ans, (ll) (j - i + 1));
        //     debug(cur);
        // }
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
