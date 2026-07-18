/*
Problem link:  https://codeforces.com/contest/1928/problem/A
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


void solve() {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    if (a % 2 == 0) {
        int x = min(a / 2, 2 * b);
        int y = max(a / 2, 2 * b);
        if (x != a || y != b) {
            cout << "YES" << endl;
            return;
        }
    }
    if (b % 2 == 0) {
        int x = min(b / 2, 2 * a);
        int y = max(b / 2, 2 * a);
        if (x != a || y != b) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
