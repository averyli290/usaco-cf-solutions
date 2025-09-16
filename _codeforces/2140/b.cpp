/*
Problem link: https://codeforces.com/contest/2140/problem/B
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


/*
x # 2x = 0 mod 3
x # 2x = 0 mod x
=> x # 2x = 0 mod (3x)
*/


void solve() {
    ll x; cin >> x; cout << 2 * x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
