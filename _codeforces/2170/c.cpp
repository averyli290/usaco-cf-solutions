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
prioritize q or r first?

map larger q to smaller r, less flexibility if q is larger


*/

void solve() {
    ll n, k; cin >> n >> k;
    vi q(n), r(n);
    for(int i = 0; i < n; i++) cin >> q[i];
    for(int i = 0; i < n; i++) cin >> r[i];
    sort(all(r));
    sort(all(q));
    reverse(all(q));
    // multiset<int> qq(all(q));
    int ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        // cur_r is current remainder, want to match with a quotient
        // r + q * y = x, x < k
        // get the largest q for which r + q * y <= k
        // y > r otherwise would mod more
        // r + q * r
        // 
        // q * y <= k - r
        // q <= (k - r) / y
        //

        int cur_r = r[i];
        // if (-(k - cur_r) / 2 > 0) continue;
        // debug(-(k - cur_r) / (cur_r + 1) - 1);
        while(j < n && (k - cur_r) / (cur_r + 1) < q[j]) {
            j++;
        }
        if (j >= n) break;
        j++;
        ans++;
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
