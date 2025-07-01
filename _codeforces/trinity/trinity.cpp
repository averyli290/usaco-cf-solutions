/*
Avery Li
4/21/2025
Problem link: https://codeforces.com/contest/2032/problem/C
*/


/*
bounded by n - 2, can always change everything to max
changing a number to max always makes it work with any pair

*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<ll> a(n, 0);
    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    int l = 0;
    int r = 1;
    int ans = n - 2;
    while (l < n - 2) {
        cout << l << " " << r << endl;
        while (r < n - 1 && a[l] + a[r] > a[r + 1]) {
            r++;
        }
        if (a[l] + a[r] <= a[r+1]) {
            ans += r - l;
        }
        l++;
    }
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

