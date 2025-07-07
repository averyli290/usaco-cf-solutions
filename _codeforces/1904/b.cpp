/*
Problem link: https://codeforces.com/contest/1904/problem/B
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<ll> vll;


void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vll b = a;
    sort(all(b));
    vll pref(n + 1, 0);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }
    for(int i = 0; i < n; i++) {
        int elt = a[i];
        int start = upper_bound(all(b), elt) - 1 - b.begin();
        int ans = start;
        while (start + 1 < n) {
            if (pref[start + 1] >= b[start + 1]) {
                ans++;
                start++;
            } else {
                break;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
