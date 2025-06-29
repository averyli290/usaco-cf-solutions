/*
Avery Li
4/28/2025
Problem link: https://codeforces.com/contest/2104/problem/A
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if ((a + b + c) % 3 != 0) {
        cout << "NO" << endl;
        return;
    }
    if (c - (b - a) < b) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
