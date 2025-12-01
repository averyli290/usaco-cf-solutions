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
    if (n > 10 * 60) {
        // if (n - 600 < 45) {
        //     cout << 45 << endl;
        // } else {
        //     cout << n - 10 * 60 << endl;
        // }
        cout << max(45, n - 60 * 10)  << endl;
    } else if (n > 60 * 9) {
        cout << max(30, min(n - 60 * 9, 45)) << endl;
    } else if (n > 360) {
        cout << min(n - 6*60, 30) << endl;
    } else {
        cout << 0 << endl;
    }
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
