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

/*

1 2 3 4 5 6 7
  x       y
*/

void solve() {
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    if (n <= 3) {
        cout << 1 << endl;
        return;
    }

    if (x1 > x2) swap(x1, x2);

    cout << k + min(x2 - x1, n - x2 + x1) << endl;
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
