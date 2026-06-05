/*
Problem link: https://codeforces.com/contest/1805/problem/A
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
    int res = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        res ^= x;
    }
    if (n % 2 == 0) {
        if (res == 0) cout << 0 << endl;
        else cout << -1 << endl;
    } else {
        cout << res << endl;
    }
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
