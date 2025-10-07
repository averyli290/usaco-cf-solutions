/*
Problem link: https://codeforces.com/contest/2127/problem/C
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
if k even then Bahamin just switch back
if k odd then Ali can make single best choice

either swap the two a values or swap two b values (actually they are same thing)
a1 a2 -> a2 a1
b1 b2    b1 b2

a1 a2 -> a1 a2
b1 b2    b2 b1

swap a1 and b2 (swap a1 and b1 is same value)
a1 a2 -> b2 a2
b1 b2    b1 a1

sort by b, calc, sort by a, calc
want adjacent b1 and b2 => adjacent a1 and a2 to minimize difference

*/

void solve() {
    int n, k; cin >> n >> k;
    vll a(n);
    vll b(n);
    vector<pair<ll, ll>> c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        c[i] = pair<ll, ll>{max(a[i], b[i]), min(a[i], b[i])};
    }
    sort(all(c));
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    ll add = LLONG_MAX;
    for(int i = 0; i < n - 1; i++) {
        auto [a1, b1] = c[i];
        auto [a2, b2] = c[i + 1];
        // ll cur = abs(a[i] - b[i]) + abs(a[i + 1] - b[i + 1]);
        // add = max(add, cur - ((abs(a[i + 1] - b[i]) + abs(a[i] - b[i + 1]))));
        // add = max(add, cur - ((abs(b[i + 1] - b[i]) + abs(a[i] - a[i + 1]))));
        ll cur = abs(a1 - b1) + abs(a2 - b2);
        add = min(add, ((abs(a2 - b1) + abs(a1 - b2))) - cur);
        add = min(add, ((abs(b2 - b1) + abs(a1 - a2))) - cur);
        // cout << a1 << " " << a2 << endl;
        // cout << b1 << " " << b2 << endl;
        // debug(add);
    }
    // debug(ans);
    add = max(0LL, add);
    ans += add;
    // debug(ans);
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
