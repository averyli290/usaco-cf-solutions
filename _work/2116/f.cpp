/*
Problem link: https://codeforces.com/contest/2116/problem/B
*/


#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

ll MOD = 998244353LL;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n; cin >> n;
    vector<ll> p(n);
    vector<ll> q(n);
    vector<ll> c(n, -1);
    for(int i = 0; i < n; i++) { cin >> p[i]; }
    for(int i = 0; i < n; i++) { cin >> q[i]; }
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        ll a = c[p[i]];
        ll a = c[p[i]];
        ll cur = max(binpow(2, p[i], MOD) + binpow(2, q[i], MOD), cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
