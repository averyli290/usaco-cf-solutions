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
    for(int i = 0;i < n; i++) {
        cin >> a[i];
    }
    if (*min_element(all(a)) == -1) {
        cout << 0 << endl;
        int last_idx = n - 1;
        while (a[last_idx] != -1) last_idx--;
        ll s = 0LL;
        for(ll &v : a) {
            if (v == -1) {
                v = 0LL;
            }
            s += v;
        }
        last_idx
    } else {
        cout << accumulate(all(a), 0LL) << endl;
        for (ll v : a) cout << v << " ";
        cout << endl;
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
