/*
Avery Li
5/1/2025
Problem link: https://codeforces.com/contest/2108/problem/A
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    if (n == 2) {
        cout << 2 << endl;
        return;
    }
    if (n % 2 == 0) {
        cout << ((n*n)/2+2)/2 << endl;
        return;
    }
    cout << ((n*n-1)/2+2)/2 << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
