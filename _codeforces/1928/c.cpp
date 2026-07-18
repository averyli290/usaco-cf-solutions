/*
Problem link:  https://codeforces.com/contest/1928/problem/B
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

n % (2k - 2) <= k && n % (2k - 2) == x % k
n % (2k - 2) > k && k - ((n % (2k - 2)) - k) == x

n - x

*/

set<ll> f(ll x) {
    set<ll> fact;
    for(ll d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            fact.insert(d);
            fact.insert(x/d);
        }
    }
    return fact;
}

void solve() {
    ll n, x; cin >> n >> x;
    // debug(n + (x - 2));
    set<ll> a = f(n - x);
    set<ll> b = f(n + (x - 2));
    set<ll> c;
    a.erase(1);
    b.erase(1);
    for(ll t : a) {
        if (t % 2 == 1) continue;
        ll k = t / 2 + 1;
        // if (t % 2 == 0 && t >= x) {
        if (n % (2*k - 2) <= k && n % (2*k - 2) == x % k && k >= x) {
            c.insert(t);
        }
    }
    for(ll t : b) {
        if (t % 2 == 0 && (t + 2) / 2 >= x) {
            c.insert(t);
        }
    }
    // for(ll t : c) cout << t << " ";
    // cout << endl;
    cout << sz(c) << endl;
    
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
