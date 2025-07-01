#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<ll> c(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    ll m = 0;
    for (int i = 0; i < n - 3; i++) {
        m = max(m, c[i] * c[i + 1] * c[i + 2]);
    }
    cout << m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
