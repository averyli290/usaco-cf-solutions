/*
Avery Li
2/25/2025
Problem link:
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    ll a = count(s.begin(), s.end(), '_');
    ll b = count(s.begin(), s.end(), '-');
    if (b < 2 || a < 1) {
        cout << 0 << endl;
    } else {
        cout << (b / 2) * (b - b / 2) * a << endl;;
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
