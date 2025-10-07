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
check if going all the way to left or right is possible versus up and down
take max of both vertical and horizontal cases, because can reduce both at same time no matter what
*/

void solve() {
    int n; cin >> n;
    int rk, ck, rd, cd;
    cin >> rk >> ck >> rd >> cd;
    // run in one direction
    int ans = 0;

    // left right
    if (ck < cd) {
        ans = max(ans, cd);
    } else if (ck > cd) {
        ans = max(ans, n - cd);
    }
    // up down
    if (rk < rd) {
        ans = max(ans, rd);
    } else if (rk > rd) {
        ans = max(ans, n - rd);
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
