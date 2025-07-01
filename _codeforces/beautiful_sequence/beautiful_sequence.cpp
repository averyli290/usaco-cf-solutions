/*
Avery Li
4/21/2025
Problem link: https://codeforces.com/problemset/problem/2069/C
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

#define MOD 998244353;

void solve() {
    // for each 2:
    // get index of rightmost 3
    // get index of leftmost 1
    return;
    int n; cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    vector<int> c(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            b[i]++;
        }
    }
    for (int i = n - 1; i > -1; i--) {
        if (a[i] == 3) {
            c[i]++;
        }
    }
    for(int i = 0; i < n; i++) {

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
