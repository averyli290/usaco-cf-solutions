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

1 2 3 4
1 2 3 1
1 2 1 1

9 10
9 2

*/

void solve() {
    int n; cin >> n;
    int top = n;
    int cur = n - 1;
    int thresh = (int) (ceil(sqrt(n)));
    int tot = 0;
    vector<pii> ops;
    while(cur >= 2) {
        if (cur == thresh) {
            ops.emplace_back(top, cur);
            ops.emplace_back(top, cur);
            // cout << top << " "<< cur << endl;
            // cout << top << " "<< cur << endl;
            top = thresh;
            thresh = (int) (ceil(sqrt(top)));
        } else {
            ops.emplace_back(cur, top);
            // cout << cur << " " << top << endl;
        }
        cur--;
    }
    cout  << sz(ops) << endl;
    for (auto [a, b] : ops) cout << a << " " << b << endl;
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
