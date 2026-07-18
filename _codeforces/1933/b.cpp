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
    vi a(n);
    int tot = 0;
    bool r1 = false;
    bool r2 = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
        if (a[i] % 3 == 1) r1 = true;
        if (a[i] % 3 == 2) r2 = true;
    }
    if (tot % 3 == 0) {
        cout << 0 << endl;
        return;
    }
    if (tot % 3 == 1 && r1) {
        cout << 1 << endl;
        return;
    }
    if (tot % 3 == 2) {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
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
