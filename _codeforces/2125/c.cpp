/*
Problem link: https://codeforces.com/contest/2125/problem/C
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
    ll l, r; cin >> l >> r;
    ll ans = r - l + 1;
    for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
    for (int c = 0; c <= 1; c++) {
    for (int d = 0; d <= 1; d++) {
        ll cur = 1;
        cur *= (a ? 2 : 1);
        cur *= (b ? 3 : 1);
        cur *= (c ? 5 : 1);
        cur *= (d ? 7 : 1);
        if (cur > 1) {
            if ((a + b + c + d) % 2 == 1) {
                ans -= r / cur - l / cur + (l % cur == 0 ? 1 : 0);
            } else {
                ans += r / cur - l / cur + (l % cur == 0 ? 1 : 0);
            }
        }
    }
    }
    }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}