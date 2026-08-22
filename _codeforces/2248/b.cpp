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
sort
process greatest to least
b[i] possible if leq a[i]
if eq fine already
if less, just need a number less
*/

void solve() {
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    if (m > n / 2) {
        cout << "NO" << endl;
        return;
    }
    sort(all(a));
    sort(all(b));
    reverse(all(b));
    reverse(all(a));
    for(int i = 0; i < m; i++) {
        if (b[i] > a[i]) {
            cout << "NO" << endl;
            return;
        }
        // cant be eq
        // match ith largest elt of b with ith largest element
        // of smallest m-size segment of a after sorting
        if (b[i] < a[n - 1 - (m - i - 1)]) {    // greedy choose from smallest segment in a left to right
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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