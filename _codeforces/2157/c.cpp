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
    int n, k, q;
    cin >> n >> k >> q;
    vi ans(n);
    vi lab(n, 0);
    vi c(q);
    vi l(q);
    vi r(q);
    for(int i = 0; i < q; i++) {
        cin >> c[i] >> l[i] >> r[i];
        l[i]--; r[i]--;
        for(int j = l[i]; j <= r[i]; j++) {
            lab[j] = c[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if (lab[j] == )
    }
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
