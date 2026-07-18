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
a=b-(k(k+1))/2
b-a=k(k+1)/2


*/

void solve() {
    ll n, a, b; cin >>n >> a >> b;
    ll curans = 0ll;
    ll k = b - a;
    // debug(k);
    k = max(0ll, min(k, min(n, b)));
    // debug(k);
    curans = max(curans, (n - k) * a + (b * k - (k * (k - 1)) / 2));
    cout << curans << endl;
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
