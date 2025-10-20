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
a_i - b_i > b_j - a_j
*/

void solve() {
    int n; cin >> n;
    vi a(n);
    vi b(n);
    multiset<int> c;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 1; i < n; i++) {
        c.insert(b[i] - a[i]);
    }

    ll ans = 0LL;
    for(int i = 0; i < n; i++) {
        c.erase(c.find(a[i]));
        cout << (ll) (lower_bound(c.begin(), c.end(), a[i] - b[i] + 1) - c.begin()) << endl;
        ans += (ll) (lower_bound(c.begin(), c.end(), a[i] - b[i] + 1) - c.begin());
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
