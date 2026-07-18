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
note that if two good sections can be combined, they cant overlap
if they did overlap, then they would share numbers, but then they definitely cannot be combined

can find every good subsegment in O(n^2)
how to check if good subsegment?
calculate all good subsegments starting from i from 0 to n
for each i, check increasing lengths j
if we encounter a duplicate element (use bool vector) then subsegment starting from i
cannot be considered from this j and beyond, so just break
otherwise, keep track of min and max val, if the difference is equal to j - i, then good subsegment
and label in 2d lookup table
*/

void solve() {
    int n; cin>> n;
    vi a(n);
    for(int i =0;i<n;i++) cin >> a[i];

    vector<vector<bool>> goodge(n + 1, vector<bool>(n + 1, false)); // good sections
    for(int i = 0; i < n; i++) {
        // get all good sections which start at i
        vector<bool> dup(n + 1, false);
        dup[a[i]] = true;
        int maxval = a[i];
        int minval = a[i];
        // debug(i);
        // debug(a[i]);
        goodge[minval][maxval] = true;
        for(int j = i + 1; j < n; j++) {
            if (dup[a[j]]) break; // can no longer be good since starting from a[i] and found some a[j] == a[i]
            dup[a[j]] = true;
            maxval = max(a[j], maxval);
            minval = min(a[j], minval);
            if (maxval - minval == j - i) {
                goodge[minval][maxval] = true;
            }
            // debug(1);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n / 2; i++) {
        // debug(i);
        for(int j = i; j <= n - i; j++) {
            // debug(j - i + 1);
            if(goodge[j - i + 1][j] && goodge[j + 1][j + i]) {
                // cout << j - i + 1 << " " << j << ", " << j + 1 << " " << j + i << endl;
                ans = i;
            }
        }
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
