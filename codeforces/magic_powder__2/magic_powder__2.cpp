/*
Avery Li
4/9/2025
Problem link: https://codeforces.com/contest/670/problem/D2
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n, 0);
    vector<ll> b(n, 0);

    ll l = 0;
    ll h = 0;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        h += (b[i] + k) / a[i];
    }
    
    while (l < h) {
        ll m = (l + h + 1) / 2;
        int cur = k;
        for(int i = 0; i < n; i++) {
            cur += min((ll) 0, b[i] - (a[i] * m));
            if(cur < 0) break;
        }
        if (cur < 0) {
            h = m - 1;
        } else {
            l = m;
        }
    }

    cout << l << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
