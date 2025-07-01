/*
Avery Li
4/20/2025
Problem link: https://codeforces.com/problemset/problem/2065/E
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
    int t = max(m, n);
    n = min(m, n);
    m = t;

    for (int i = 0; i < k; i++) {
        s += "0";
    }

    for (int i = 0; i < m + n - k; i++) {
        if (i % 2 == 0) {
            s += "1";
        } else {
            s += "0";
        }
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
