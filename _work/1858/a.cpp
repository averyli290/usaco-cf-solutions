/*
Problem link: https://codeforces.com/contest/1858/problem/A
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if (c % 2 == 0) {
        if (a <= b) {
            cout << "Second" << endl;
            return;
        } else {
            cout << "First" << endl;
            return;
        }
    } else {
        if (a < b) {
            cout << "Second" << endl;
            return;
        } else {
            cout << "First" << endl;
            return;
        }
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
