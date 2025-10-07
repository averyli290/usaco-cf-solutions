/*
Problem link: https://codeforces.com/contest/2151/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;
const long long MAXN = 2*10E5+2;
const long long m = 998244353;

/*
there are exactly a_k black cells in each row k
there is exactly one colored black cell in each L shape (1x1, 2x2, 3x3) forward and backward

4
3 1 0 0

x x . x
. . x .
. . . .
. . . .

x . x x
. x . .
. . . .
. . . .

sum of colored cells must be exactly num of cols

can only be colored in top triangle, (intersect the L pieces)
must all be different columns

*/

vll factorial;

long long inv(long long a) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}

long long binomial_coefficient(ll n, ll k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % m) % m;
}

void solve() {
    ll n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = accumulate(all(a), 0LL);
    if (sum != n) {
        cout << 0 << endl;
        return;
    }
    // check if anything below triangle (not possible)
    for(int i = (n + 1)/2; i < n; i++) {
        if (a[i] > 0) {
            cout << 0 << endl;
            return;
        }
    }

    ll used = 0LL;
    ll ans = 1LL;
    for(ll i = (n - 1) / 2; i >= 0; i--) {
        ll width = ((n - 1) / 2 + 1 - i) * 2 - (n % 2);
        if (used + a[i] > width) {  // cannot choose greater than width
            cout << 0 << endl;
            return;
        }
        //cout << "left: " << width - used << endl;
        ans *= binomial_coefficient(width - used, a[i]);
        ans %= m;
        used += a[i];
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    factorial.resize(MAXN);
    factorial[0] = 1LL;
    for (ll i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
