/*
Problem link: https://codeforces.com/contest/2119/problem/C
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
include first even number of times as much as possible
*/

void solve() {
    ll n, l, r, k; cin >> n >> l >> r >> k;
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    if (n % 2 == 1) {
        cout << l << endl;
        return;
    }
    ll right = 1;
    while (right <= l) right <<= 1;
    if (right > r) {
        cout << -1 << endl;
        return;
    }
    if (n - k < 2) {
        cout << right << endl;
    }
    else {
        cout << l << endl;
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
