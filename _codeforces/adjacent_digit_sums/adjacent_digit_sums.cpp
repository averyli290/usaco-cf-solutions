/*
Avery Li
2/25/2025
Problem link: https://codeforces.com/contest/2067/problem/A
*/

/*
S(n)=x
S(n+1)=y

S(n+1)=S(n)+1 if n[-1]<9

if n[-1]=9 and n[-2] < 9, S(n+1) = S(n) - 9 + 1 = S(n) - 9 * 1 + 1
if n[-1]=9, n[-2] = 9, n[-3] < 9, S(n+1) = S(n) - 9 - 9 + 1 = S(n) - 9 * 2 + 1

x = 1, y = 2
100

109 -> 110
99 -> 100

x = 18, y = 10
909 -> 910

*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        cin >> x >> y;
        if (y == x + 1) {
            cout << "YES" << endl;
        } else if (y < x && (x + 1 - y) % 9 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
