/*
Problem link: https://codeforces.com/contest/2112/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int a, x, y;
    cin >> a >> x >> y;
    if (x > y) swap(x, y);
    if (a >= x && a <= y) {
        cout << "NO" << endl;
        return;
    }
    if (min(abs(a - x), abs(a - y)) > (x - y) / 2 + (x - y) % 2) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
