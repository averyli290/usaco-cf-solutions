/*
Avery Li
4/27/2025
Problem link: https://codeforces.com/contest/2098/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> a;
    int m = INT_MAX;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[k]++;
        m = min(k, m);
    }

    int prev = m - 2;
    int cur = 2;
    for(auto& [k, v] : a) {
        if (k - 1 != prev) {
            cur = 2;
        }
        
        if (v >= 4) {
            cur -= 2;
        } else if (v >= 2) {
            cur -= 1;
        } else if (v >= 1) {
            cur = cur;
        }

        if (cur <= 0) {
            cout << "Yes" << endl;
            return;
        }
        prev = k;
    }
    cout << "No" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
