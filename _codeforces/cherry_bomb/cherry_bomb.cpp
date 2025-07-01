/*
Avery Li
4/24/2025
Problem link: https://codeforces.com/contest/2106/problem/C
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int required = -1;
    int max_sum = -1;
    int min_b = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            if (required == -1) {
                required = a[i] + b[i];
            } else if (required != a[i] + b[i]) {
                cout << 0 << endl;
                return;
            }
            min_b = min(min_b, b[i]);
            if (min_b == -1) {
                min_b = b[i];
            }
            max_sum = max(max_sum, a[i] + b[i]);
        }
    }

    if (required != -1) {
        for (int i = 0; i < n; i++) {
            if (required < a[i] || required - a[i] > k) {
                cout << 0 << endl;
                return;
            }
        }
        if (min_b != -1) {
            cout << 1 << endl;
            return;
        }
    }
    cout << (*min_element(a.begin(), a.end())+ k) - *max_element(a.begin(), a.end()) + 1 << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
