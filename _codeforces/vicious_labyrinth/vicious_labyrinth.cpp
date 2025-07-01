/*
Avery Li
2/27/2025
Problem link: https://codeforces.com/contest/2078/problem/B
*/

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;


using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            cout << n - 1;
        } else if (i == n - 1) {
            cout << n;
        } else if (k % 2 == 1) {
            cout << n;
        } else {
            cout << n - 1;
        }
        cout << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
