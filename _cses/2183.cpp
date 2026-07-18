/*
Problem link: https://cses.fi/problemset/task/2183/
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0;i < n ; i++) cin >> a[i];
    sort(all(a));
    ll maxval = 0ll;
    for(int i = 0; i < n; i++) {
        // debug(a[i]);
        if (a[i] > maxval + 1) {
            cout << maxval + 1 << endl;
            return;
        }
        maxval += a[i];
    }
    cout << maxval + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
