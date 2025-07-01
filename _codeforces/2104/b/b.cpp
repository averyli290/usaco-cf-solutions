/*
Avery Li
4/28/2025
Problem link: https://codeforces.com/contest/2104/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // prefix max
    vector<ll> pre(n);
    ll cur = -1;
    for(int i = 0; i < n; i++) {
        cur = max(cur, a[i]);
        pre[i] = cur;
    }

    // suffix sum
    vector<ll> suf(n + 1);
    cur = 0;
    for(int i = n - 1; i >= 0; i--) {
        cur += a[i];
        suf[i] = cur;
    }
    suf[n] = 0;

    for(int k = 1; k <= n; k++) {
        ll x = suf[n - k];
        ll y = 0;
        if (n - k - 1 >= 0) {
            y = suf[n - k + 1] + pre[n - k - 1];
        } 
        cout << max(x, y) << " ";
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
