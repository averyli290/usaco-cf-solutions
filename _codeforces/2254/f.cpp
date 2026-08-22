/*
Problem link:
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*
https://www.youtube.com/watch?v=9qN9EF-6IcI

if apply i, then j
a[j] ^= a[i]

then, all other idxs a[k] will be affected by a[i] twice,
first a[k] ^= a[i], a[j] ^= a[i]
(a[k] ^ a[i]) ^ (a[j] ^ a[i]) = a[k] ^ a[j],
but a[j] will be (a[j] ^ a[i])

if apply i, then j, then k
by above, a[l] -> a[l] ^ a[j] after i and j applied
(a[l] ^ [j]) ^ (a[k] ^ a[j])
=a[l] ^ a[k]

always takes the last one which has been applied

set of values either equals arr a or arr a after exactly one operation

checking each value would be slow, is there a target value which is needed?

how to get if the permutation is possible? can create any permutation probably
by applying indices in different orders
*/


void solve() {
    int n; cin >> n;
    vll a(n), b(n);
    for(int i = 0; i < n ;i++) cin >> a[i];
    for(int i = 0; i < n ;i++) cin >> b[i];
    sort(all(a));
    sort(all(b));
    bool good = true;
    for(int i = 0 ; i < n; i++) {
        if (a[i] != b[i]) {
            good = false;
            break;
        }
    }
    if (good) {
        cout << "YES" << endl;
        return;
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
