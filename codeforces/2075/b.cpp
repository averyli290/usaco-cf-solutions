/*
Problem link: https://codeforces.com/contest/2075/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve() {
    int n, k; cin >> n >> k;
    vll a(n);
    for(int i = 0;i < n; i++) { cin >> a[i]; }
    vll b = a; sort(all(b));
    if (k == 1) {
        cout << max(a[0] + *max_element(a.begin() + 1, a.end()), a[n - 1] + *max_element(a.begin(), a.begin() + n - 1)) << endl;
        return;
    }
    cout << accumulate(b.rbegin(), b.rbegin() + k + 1, 0LL) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
