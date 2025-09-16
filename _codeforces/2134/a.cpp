/*
Problem link: https://codeforces.com/contest/2134/problem/A
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
    int n, a, b; cin >> n >> a >> b;
    if (n % 2 != b % 2) {
        cout << "NO\n";
        return;
    }
    if (n % 2 != a % 2 && a > b) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
