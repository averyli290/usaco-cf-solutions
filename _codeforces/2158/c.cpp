/*
Problem link: https://codeforces.com/contest/2158/problem/C
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
    int n, k; cin >> n >> k;
    vll a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if(k % 2 == 0) {
        ll ans = a[0];
        ll cur = a[0];
        for(int i = 1; i < n; i++) {
            cur = max(a[i], cur + a[i]);
            ans = max(ans, cur);
        }
        cout << ans << endl;
    } else {
        ll ans = a[0] + abs(b[0]);
        ll cur = a[0];
        ll best_change = abs(b[0]);
        for(int i = 1; i < n; i++) {
            if (a[i] + abs(b[i]) > cur + a[i] + max(abs(b[i]), best_change)) {
                best_change = abs(b[i]);
                cur = a[i];
            } else if (a[i] + abs(b[i]) == cur + a[i] + max(abs(b[i]), best_change)) {
                if (abs(b[i]) > best_change) {
                    best_change = abs(b[i]);
                    cur = a[i];
                } else {
                    cur += a[i];
                }
            } else {
                best_change = max(abs(b[i]), best_change);
                cur += a[i];
            }
            ans = max(ans, cur + best_change);
        }
        cout << ans << endl;
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
