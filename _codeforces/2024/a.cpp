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
a - x = (b - a + 1) / 2;

a - x = b - 2x
a - b = - 3x
3x = b - a
*/

void solve() {
    int a, b; cin >> a >> b;
    if (a >= b) {
        cout << a << endl;
    } else {
        int need = b - a;
        if (a < need) {
            cout << 0 << endl;
        } else {
            cout << a - need << endl;
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
