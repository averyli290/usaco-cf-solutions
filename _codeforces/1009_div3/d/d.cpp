/*
Avery Li
5/27/2025
Problem link: https://codeforces.com/contest/2074/problem/D
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, z; cin >> n >> z;
    vector<ll> x(n);
    vector<ll> r(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> r[i];
    }

    // get min and max y (will be same) for each x (each can can be found using radius and center)
    map<ll, ll> m;
    for (ll i = 0; i < n; i++) {
        for(ll j = -r[i]; j <= r[i]; j++) {
            ll y = sqrtl(r[i] * r[i] - j * j) + 5;          // sqrtl much faster, overestimate
                                                            // and count downwards to get y
            while (y * y > r[i] * r[i] - j * j) {
                y--;
            }
            m[x[i] + j] = max(m[x[i] + j], 2 * y + 1);
            //cout << y << endl;
        }
    }

    ll ans = 0;
    for (auto [k, v] : m) {
        ans += v;
        //cout << "k, v" << k << " " << v << endl;
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
