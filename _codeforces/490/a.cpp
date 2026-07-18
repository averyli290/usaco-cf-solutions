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
    vi a,b,c;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == 1) a.push_back(i);
        if (x == 2) b.push_back(i);
        if (x == 3) c.push_back(i);
    }
    int m = min(sz(a), min(sz(b),sz(c)));
    cout << m << endl;
    for(int i = 0; i < m; i++) {
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }
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
