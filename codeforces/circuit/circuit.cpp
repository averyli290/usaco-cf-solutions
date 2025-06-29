/*
Avery Li
4/21/2025
Problem link: https://codeforces.com/contest/2032/problem/A
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n, 0);
    int c = 0;
    for(int i = 0; i <  2*n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            c++;
        }
    }
    cout << c % 2 << " ";
    if (c < n) {
        cout << c;
    } else {
        cout << 2 * n - c;
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
