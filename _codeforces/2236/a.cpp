/*
Problem link:
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
    int m = 0;
    int m2 = INT_MAX;
    vi a(n);
    for(int i= 0;i < n; i++) {
        cin >> a[i];
        m = max(a[i], m);
        m2 = min(m2, a[i]);
    }
    for(int i= 0;i < n; i++) {
        if (a[i] != a[0]) {
            cout << m + 1 - m2 << endl;
            return;
        }
    }
    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
