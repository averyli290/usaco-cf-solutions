/*
Problem link: https://codeforces.com/contest/2244/problem/C
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
1 3 2 5 4
3

1 3 2 5 4
1 4 2 5 3

7 1 3 4 5 6 2 8
3 5
*/

void solve() {
    int n, x, y; cin >> n >> x >> y;
    int ct = 0;
    vi p(n);
    int s = gcd(x, y);

    for(int i = 0; i< n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) {
        if (abs(p[i] - (i + 1)) % s != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
    if (x % 2 != y % 2) {
        cout << "YES" << endl;
        return;
    }
    int smallest = gcd(x, y);
    for(int i = 0; i < n; i += 2) {
        if (p[i] % 2 != p[0] % 2) {
            cout <<"NO" << endl;
            return;
        }
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
