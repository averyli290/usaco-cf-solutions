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
const ll M = 998244353ll;

long long binpow(long long a, long long b) {
    a %= M;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n,m,r,c;
    cin >> n >> m >> r >> c;
    if (r == c && c == 1) {
        cout << 1 << endl;
        return;
    }
    if (r == 1) {
        cout << binpow(binpow(2ll, c - 1), n) << endl;;
        return;
    }
    if (c == 1) {
        cout << binpow(binpow(2ll, r - 1), m) << endl;;
        return;
    }
    ll h = r - 1;
    ll w = c - 1;
    ll tot = ((h * w)+ ((n - h) * w)+ ((m - w) * h));
    cout << binpow(2, tot) << endl;
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
