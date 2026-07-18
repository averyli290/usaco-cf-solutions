/*
Problem link: https://codeforces.com/contest/2241/problem/D
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

// cf why did u go down at the start of my virtual :(

void solve() {
    int n; cin >> n;
    vll a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = n - 1; i > 0; i--) {
        if (a[i] <= b[i]) {
            a[i] = b[i];
        } else {
            a[i - 1] += -(b[i] - a[i]);
            a[i] = b[i];
        }
        // debug(a[i]);
        // debug(b[i]);
    }
    // for(int i : a) cout << i << " ";
    // cout << endl;
    // for(int i : b) cout << i << " ";
    // cout << endl;
    if (a[0] <= b[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
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