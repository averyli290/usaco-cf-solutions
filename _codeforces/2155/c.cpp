/*
Problem link: https://codeforces.com/contest/2155/problem/C
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
const long long MOD = 676767677;

/*
dp[i][0] = # of valid configurations with ith wizard wearing cape on left side
dp[i][1] = # of valid configurations with ith wizard wearing cape on right side

coutn how many left can be flipped

go from edges?

do free right and free left which have a
*/

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    vi prefmax(n + 2);
    vi suffmax(n + 2);
    prefmax[0] = 0;
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
        if (i == n) {
            prefmax[i + 1] = prefmax[i];
            continue;
        }
        prefmax[i + 1] = max(a[i], prefmax[i]);
    }
    suffmax[n + 1] = 0;
    for(int i = n; i >= 0; i--) {
        if (i == 0) {
            suffmax[i] = suffmax[i + 1];
            continue;
        }
        suffmax[i] = max(a[i - 1], suffmax[i + 1]);
    }
    int minval = 1000000;
    for(int i = 0; i < n; i++) {
        int to_left = i;
        int to_right = n - i - 1;
        int free_left = to_left;
        int free_right = to_right;
        if (a[i] - 1 - to_right > 0) {
            free_left -= a[i] - to_right;
        }
        if (a[i] - 1 - to_left > 0) {
            free_right -= a[i] - to_left;
        }
        // debug(a[i]);
        // debug(free_left);
        // debug(free_right);
        int idx = i + 1;
        int othermax = max(prefmax[idx - 1], suffmax[idx + 1]);
        int cur = free_left + free_right + (othermax == n ? 0 : 1);
        minval = min(minval, cur);
    }
    cout << binpow(2, minval, MOD) << endl;
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
