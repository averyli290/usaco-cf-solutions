/*
Problem link: https://codeforces.com/contest/1921/problem/D
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
*/


void solve() {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    int d = xa - ya;
    if (d < 0) {
        cout << "Draw" << endl;
        return;
    }
    if (abs(ya - yb) <= 1) {
        cout << (d % 2 == 1) ? "Alice" : "Bob" << endl;
        return;
    }
    if (ya < yb) {

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
