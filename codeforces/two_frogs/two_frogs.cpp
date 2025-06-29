/*
Avery Li
4/15/2025
Problem link: https://codeforces.com/contest/2055/problem/A
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if ((a - b) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
