/*
Problem link: https://codeforces.com/contest/2125/problem/B
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


void solve() {
    ll a, b, k; cin >> a >> b >> k;
    ll c = gcd(a, b);
    if (a / c <= k && b / c <= k) {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}