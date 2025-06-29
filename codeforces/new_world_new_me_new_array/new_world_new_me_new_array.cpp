/*
Avery Li
2/25/2025
Problem link: https://codeforces.com/contest/2072/problem/A
*/

/*


*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int n, k, p;
void solve() {
    cin >> n >> k >> p;
    if (abs(k) > p * n) {
        cout << -1 << endl;
    } else {
        cout << abs(k) / p + (abs(k) % p > 0 ? 1 : 0) << endl;
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
