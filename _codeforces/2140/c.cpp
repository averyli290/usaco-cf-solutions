/*
Problem link: https://codeforces.com/contest/2140/problem/C
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
bob should end on his turn no matter what
alice can undo bob's move and get more score every time
find best move for alice
*/

void solve() {
    int n; cin >> n;
    vll a(n);
    multiset<ll> evens, odds;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        // if (i % 2==0) evens.insert({a[i] - i, i});
        // else odds.insert({a[i] - i, i});
    }

    ll baseans = 0LL;
    for(int i = 0; i < n; i++) {
        if (i % 2 == 0) baseans += a[i];
        else baseans -= a[i];
    }
    ll ans = baseans + (n - 1) / 2 * 2;
    ll modd = -INF;
    ll meven = -INF;

    for(int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans = max(ans, baseans + modd - a[i] * 2 + i);
            meven = max(meven, -a[i] * 2 - i);
        } else {
            ans = max(ans, baseans + meven + a[i] * 2 + i);
            modd = max(modd, a[i] * 2 - i);
        }
        // debug(i);
        // debug(ans);
    }
    cout << ans << endl;




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
