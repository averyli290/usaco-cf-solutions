/*
Avery Li
4/13/2025
Problem link: https://codeforces.com/contest/2094/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    cout << max(-m, l) << " " << l - max(-m, l) + max(0, m + l) << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
