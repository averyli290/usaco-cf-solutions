/*
Avery Li
5/1/2025
Problem link: https://codeforces.com/contest/2108/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

/*

for x == 0 and x == 1 handle differently

if number of set bits greater than or equal to n, can set those bits using n numbers

if even parity, toggle last bit using 1

if odd parity, use 2 xor 3 to obtain 1, account for 2 + 3 = 5, 3 more than 1 + 1 usual

*/

void solve() {
    ll n, x; cin >> n >> x;
    if (x == 0) {
        if (n == 1) {
            cout << -1 << endl;
            return;
        }
        if (n % 2 == 0) {
            cout << n << endl;
            return;
        } else {
            cout << n + 3 << endl;
            return;
        }
    } else if (x == 1) {
        if (n % 2 == 0) {
            cout << n + 3 << endl;
            return;
        } else {
            cout << n << endl;
            return;
        }
    }

    int a = __builtin_popcount(x);
    if (a >= n) {
        cout << x << endl;
        return;
    }

    int left = n - a;
    if (left % 2 == 0) {
        cout << x + n - a << endl;
        return;
    }
    cout << x + 2 + (n - a - 1) << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
