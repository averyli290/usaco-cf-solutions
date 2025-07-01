/*
Avery Li
5/2/2025
Problem link: https://codeforces.com/problemset/problem/2094/F
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int c = 1LL * n * m / k;
    int cur = 0;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << cur % k + 1 << " ";
            cur++;
        }
        // when m % k == 0, row above will can have matching
        if (m % k == 0) {
            cur++;
        }
        cout << endl;
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
