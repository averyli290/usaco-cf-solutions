/*
Problem link: https://codeforces.com/contest/2154/problem/B
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
a b c

a <= b <= c

b = c
c -= 1

a >= b >= c
c = max(a, b, c)

3 3 2 1

2 3 2 1

*/

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    int curmax = a[0];
    for(int i = 0; i < n; i++) {
        curmax = max(a[i], curmax);
        if (i % 2 == 1) a[i] = curmax;
    }
    // debug_vector(a, sz(a));
    for(int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) { // odd case
            if (a[i] >= a[i + 1]) {
                ans++;
            }
            a[i]--;
        } else { // even case
            if (a[i] <= a[i + 1]) {
                ans += a[i + 1] - a[i] + 1;
                a[i + 1] = a[i] - 1;
            }
        }
    }
    // debug_vector(a, sz(a));
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
