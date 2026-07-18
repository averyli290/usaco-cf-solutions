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

0A: 6 8 2 4 2
B: 6 2 2 4 8
1A: 3 1 1 2 4


use x=01...1 to determine if even or odd?

x=01...1
differentiate between & and |
if return val is odd, |
otherwise, if there is at least 1 extra 0, then &
otherwise, (v = x and ty=&) or ty=|


if & for sure, use m0=0.1.0, m1=0.0.0

otherwise, (v = x and ty=&) or ty=|
m0=01...1, m1=1...1
if ty = | and retval odd, m0^v odd and m1^v even
if ty = | and retval even, m0^v even and m1^v odd
if ty = & and v = 01...1, m0^v even
if ty = & and v = 01...1, m0^v even

m0=10...0, m1=0...0
if ty = | and retval odd, m0^v even and m1^v odd

if ty = | and retval even, m0^v odd and m1^v even
if ty = & and v = 01...1, m0^v even
*/


const ll m = 1e9+7;
const ll MAXN = 2e5;

vll factorial;

ll inv(ll a) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}

long long C(int n, int k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % m) % m;
}


void solve() {
    int n; cin >> n;

    vll a(n);
    ll ans = 0ll;
    int startidx = -1;

    map<ll, ll> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    ll totmult = 1ll;
    for(auto [k,v] : mp) {
        ll temp = 0ll;
        for(ll val = 0; val <= v; val+=2) {
            temp += C(v, val);
        }
        totmult *= temp;
        totmult %= m;
    }



    ll tot=0ll;
    tot += totmult;
    tot %= m;

    for(int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == 1 && mp[-1] > 0) {
            tot += totmult;
            tot %= m;
        }
    }
    cout << tot << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial.resize(MAXN + 1);
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
