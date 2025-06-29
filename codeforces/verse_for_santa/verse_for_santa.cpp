/*
Avery Li
4/19/2025
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/552145/problem/E
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    ll n, s; cin >> n >> s;
    vector<ll> a(n, 0);
    vector<ll> b(n, 0);
    vector<ll> c(n, 0);
    vector<ll> ind(n, 0);
    ll m = -1;
    ll m_ind = 0;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > m) {
            m_ind = i;
            m = a[i];
        }
        b[i] = m;
        ind[i] = m_ind;
        cur += a[i];
        c[i] = cur;
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (c[i] - b[i] <= s) {
            ans = ind[i] + 1;
        }
        if (c[i] <= s) {
            ans = 0;
        }
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
