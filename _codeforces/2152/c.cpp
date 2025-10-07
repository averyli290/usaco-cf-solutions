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
    int q; cin >> q;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi pref0(n + 1, 0);
    vi pref1(n + 1, 0);
    vi maxadj(n + 1, -1);
    for(int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) {
            maxadj[i + 1] = i;
        } else {
            maxadj[i + 1] = maxadj[i];
        }
        pref0[i + 1] = pref0[i] + (a[i] == 0 ? 1 : 0);
        pref1[i + 1] = pref1[i] + (a[i] == 1 ? 1 : 0);
    }
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        int ct0 = pref0[r] - pref0[l - 1];
        int ct1 = pref1[r] - pref1[l - 1];
        if (ct0 % 3 != 0 || ct1 % 3 != 0) {
            cout << -1 << endl;
        } else {
            int ans = ct0 / 3 + ct1 / 3;
            //debug(maxadj[r]);
            if (maxadj[r] <= l) {
                ans++;
            }
            cout << ans << endl;
        }
    }
    // 0 0 1 1 0 1 0 1 0 1 1 0
    // 0 1 0 1 0 1
    // 


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
