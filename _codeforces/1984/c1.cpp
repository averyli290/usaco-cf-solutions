/*
Problem link: https://codeforces.com/contest/1984/problem/C1
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
    for(int i = 0; i < n; i++) cin >> a[i];

    ll minval = (ll) a[0];
    ll maxval = abs((ll) a[0]);
    // debug(minval);
    // debug(maxval);
    for(int i = 1; i < n; i++) {
        ll minvaltemp = min(abs(minval + a[i]), min(abs(maxval + a[i]), min(minval + a[i], maxval + a[i])));
        ll maxvaltemp = max(abs(minval + a[i]), max(abs(maxval + a[i]), max(minval + a[i], maxval + a[i])));
        minval = minvaltemp;
        maxval = maxvaltemp;
        // debug(minval);
        // debug(maxval);
    }
    cout << maxval << endl;

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
