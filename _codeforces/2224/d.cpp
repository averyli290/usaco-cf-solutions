/*
Problem link: https://codeforces.com/contest/2224/problem/D
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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;
const long long MOD = 998244353;

/*
iterate over all pairs
for each pair, count the # of ways to invert

store swap ratios in a list, sort
(i, j) swap = 

*/

vll factorial;

ll inv(ll a) {
  return a <= 1LL ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}

void solve() {
    int n; cin >> n;
    vector<long double> a(n);
    vector<long double> b(n);
    for(int i = 0; i < n;i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n;i++) {
        cin >> b[i];
    }

    ll num = 0LL;

    ll den = 1LL;
    for(int i = 1; i <= n; i++) {
        den = (den * ((ll) i)) % MOD;
    }

    vector<long double> ratios;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i != j) ratios.push_back(b[j] / b[i]);
        }
    }

    sort(all(ratios));
    // debug(sz(ratios));
    // for(long double r : ratios) {
    //     cout << r << endl;
    // }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ll cur = 0LL;
            if (a[i] == a[j]) {
                cur = lower_bound(all(ratios), 1) - ratios.begin();
            } else {
                long double div = a[i] / a[j];
                cur = lower_bound(all(ratios), div) - ratios.begin();
            }
            // debug(a[i]);
            // debug(a[j]);
            // debug(a[i] / a[j]);
            // debug(cur);
            cur = (cur * factorial[n - 2]) % MOD;
            num = (num + ((ll) cur)) % MOD;
        }
    }

    ll g = gcd(num, den);

    // debug(num);
    // debug(den);
    num /= g;
    den /= g;

    cout << (num * inv(den)) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial.resize(2100, 0LL);
    factorial[0] = 1LL;
    for(int i = 1; i < 2100; i++) {
        factorial[i] = (factorial[i - 1] * ((ll) i)) % MOD;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
