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


void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vll b(n - 1);
    for(int i = 0; i < n - 1; i++) {
        b[i] = abs(a[i] - a[i + 1]);
    }

    vll pref(n + 3, 0LL);
    pref[0] = 0LL;
    for(int i = 0; i < n - 1; i++) {
        pref[i + 1] = pref[i] + b[i];
    }
    pref[n] = pref[n - 1];
    pref[n + 1] = pref[n];
    // for(int i = 0; i < n + 1; i++) {
    //     debug(pref[i]);
    // }
    // debug(n - 1);
    ll ans = min(pref[n] - pref[1], pref[n - 2]);
    // debug(ans);
    for(int i = 1; i < n - 1; i++) {
        ll other = abs(a[i - 1] - a[i + 1]);
        // debug(other);
        // debug(pref[i - 1]);
        // debug(pref[i - 1] + pref[n] - pref[i + 1]);
        ans = min(ans, pref[i - 1] + pref[n] - pref[i + 1] + other);
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
