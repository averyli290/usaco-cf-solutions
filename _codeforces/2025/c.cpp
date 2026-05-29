/*
Problem link: https://codeforces.com/contest/2025/problem/C
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


void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    for(int &v : a) cin >> v;
    sort(all(a));
    // for(int &v : a) cout << v << " ";
    // cout << endl;
    
    int left = 0;
    int right = 0;
    int ct = 1;
    int ans = 0;
    while(left < n) {
        right = max(right,left);
        // check that diff between right and left isn't k (5-2 -> 4 distinct)
        while(right < n - 1 && a[right + 1] - a[right] <= 1 && a[right + 1] - a[left] < k) {
            right++;
        }
        // debug(left);
        // debug(right);
        ans = max(ans, right - left + 1);
        left++;
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
