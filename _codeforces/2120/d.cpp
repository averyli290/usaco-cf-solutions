/*
Problem link: https://codeforces.com/contest/2120/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int m = 1E9 + 7;
const int MAXN = 1E5 + 10;

ll inv(ll a) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll x = a - 1;
    x = (x * k) % m;
    x = (x + 1) % m;
    ll y = k;   // k different numbers which can fulfill a entries as above
    y = (y * (b - 1)) % m;
    // choose
    //y = (y * C(x, a)) % m;
    for (int i = 0; i < a; i++) {
        y *= x - i; y %= m;
        y *= inv(a - i); y %= m;
    }

    y = (y + 1) % m;


    cout << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}