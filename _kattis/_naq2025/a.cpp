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
    int r, g, b; cin >> r >> g >> b;
    int rr = r;
    int gg = g;
    int bb = b;
    int x, y, z; cin >> x >> y >> z;
    int d, e; cin >> d >> e;
    r = max(0, r - x);
    g = max(0, g - y);
    b = max(0, b - z);
    d = max(0, d - r);
    e = max(0, e - b);
    if (d + e >= g) {
        cout << max(0, rr - x) + max(0, gg - y) + max(0, bb - z)  << endl;
    } else {
        cout << -1 << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    
}
