/*
Avery Li
4/9/2025
Problem link: https://codeforces.com/problemset/problem/2089/B1
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> orig_a(n, 0);
    vector<int> orig_b(n, 0);
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++) cin >> orig_a[i];
    for (int i = 0; i < n; i++) cin >> orig_b[i];

    vector<int> a(n, 0);
    vector<int> b(n, 0);

    int low = 0;
    int high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        //cout << low << " " << mid << " " << high << endl;
        a = orig_a; b = orig_b;

        for (int count = 0; count < mid; count++) {
            for (int i = 0; i < n; i++) {
                int t = min(a[i], b[i]);
                a[i] -= t;
                b[i] -= t;
            }

            for(int i = 0; i < n; i++) {
                c[i] = a[((i - 1) + 2 * n) % n];
            }

            a = c;

        }

        if (*max_element(a.begin(), a.end()) == 0) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
