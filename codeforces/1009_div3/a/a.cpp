/*
Avery Li
5/27/2025
Problem link: https://codeforces.com/contest/2074/problem/A
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int l, r, d, u; cin >> l >> r >> d >> u;
    if(l == r && d == r && r == u) { cout << "YES" << endl;}
    else {
        cout <<"NO" << endl;
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
