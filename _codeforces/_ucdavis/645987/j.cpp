/*
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/645987/problem/J
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
1 6 5 11
5 + 6
10 + 1

----- + 
   -----
=
-------- +
   --
can always change construction to make not crossing
*/


void solve() {
    int n; cin >> n;
    vll a(2*n);
    for(int i=0; i<2*n; i++) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    for(int i=0; i<n; i++) ans += abs(a[2*n-i-1] - a[i]);
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
