/*
Avery Li
4/24/2025
Problem link: https://codeforces.com/contest/2106/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    // print everything before x

    for(int i = 0; i < x; i++) {
        cout << i << " ";
    }

    // print everything after x
    for(int i = x + 1; i < n; i++) {
        cout << i << " ";
    }

    // print x
    if (x != n) {
        cout << x << endl;
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
