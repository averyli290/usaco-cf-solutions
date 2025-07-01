/*
Avery Li
3/27/2025
Problem link: https://codeforces.com/contest/2078/problem/A
*/

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;


using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    float s, a;
    s = 0;

    for (int i = 0; i < n; i++) {
        cin >> a;
        s += a;
    }
    if (s / n == x) {
        cout << "YES" << endl;
    }
    else {
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
