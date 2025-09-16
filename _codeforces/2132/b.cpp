/*
Problem link: https://codeforces.com/contest/2131/problem/B
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
    int n; cin >> n;
    if (n == 2) {
        cout << "-1 2" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            if (n % 2 == 0) {
                cout << 2 << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            if (i % 2 == 0) {
                cout << "-1 ";
            } else {
                cout << "3 ";
            }
        }
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