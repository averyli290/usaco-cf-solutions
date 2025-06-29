/*
Avery Li
4/21/2025
Problem link: https://codeforces.com/contest/2032/problem/B
*/

/*

need equal amount of subarrays before and after k

1 2 3 4 5
k = 2
3 1 2 3

1 2

1 2 3 4 5 6 7 8 9
if k = 5, use 1, 2, 5, 8, 9

*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    if (n == 1) {
        cout << 1 << endl << 1 << endl;
        return;
    }

    if (k == 1 || k == n) {
        cout << -1 << endl;
        return;
    }

    if (k % 2 == 0) {
        cout << 3 << endl << 1 << " " << k << " " << k + 1 << endl;
        return;
    } else {
        cout << 5 << endl << 1 << " " << 2 << " " << k << " " << k + 1 << " " << n << endl;
        return;
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
