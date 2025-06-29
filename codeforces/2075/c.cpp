/*
Problem link: https://codeforces.com/contest/2075/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;

void solve() {
    int n, m; cin >> n >> m;
    vi a(m); for(int i = 0; i < m; i++) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    ll l = m;       // num colors can use for painting left side
    ll r = 0;       // num colors can use for painting left side
    for(int i = 1; i <= n - 1; i++) {       // iterate over num boards painted on left
        while (l > 0 && a[m - l] < i) l--;  // update l
        r = (ll) (a.end() - lower_bound(all(a), n - i));
        ans += l * r - min(l, r);   // remove overcounting using same color for both sides
                                    // min(l, r) colors can be used to do this
                                    // if color can cover the larger side, it can also cover the smaller side
                                    // so it will be included in both l and r. if say, l is smaller, every color in l
                                    // also appears in r, so subtract off l from l * r to remove using same color on
                                    // both sides, vice versa
    }
    cout  << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
