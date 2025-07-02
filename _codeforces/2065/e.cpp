/*
Problem link: https://codeforces.com/contest/2065/problem/E
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    if (abs(m - n) > k || k > max(m, n)) {
        cout << -1 << endl;
        return;
    }

    string s;

    char gC = '0';
    char lC = '1';
    if (n < m) {
        swap(n, m);
        swap(gC, lC);
    }

    for (int i = 0; i < k; i++) {
        s += gC;
    }

    n -= k;
    //cout << "cur " << s << endl;

    for(int i = 0; i < min(n, m); i++) {
        s += lC;
        s += gC;
    }
    //cout << "cur " << s << endl;

    int t = min(n, m);
    n -= t;
    m -= t;
    for(int i = 0; i < max(n, m); i++) {
        s += (n == 0) ? lC : gC;
    }

    cout << s << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}