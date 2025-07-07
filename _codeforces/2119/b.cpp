/*
Problem link: https://codeforces.com/contest/2119/problem/B
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    ll px, py, qx, qy; cin >> px >> py >> qx >> qy;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // min and max distances
    ll dist = (px - qx) * (px - qx) + (py - qy) * (py - qy);
    ll mx = accumulate(all(a), 0LL);
    if (mx * mx < dist) {
        cout << "NO" << endl;
        return;
    }
    sort(all(a));
    reverse(all(a));
    ll cur_min = a[0];
    for(int i = 1 ; i < n; i++) {
        cur_min = min(cur_min, abs(cur_min - a[i]));
    }

    if (cur_min * cur_min > dist) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
