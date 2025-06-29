/*
Avery Li
4/15/2025
Problem link: https://codeforces.com/contest/2055/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n, 0); for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n, 0); for (int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        int temp = min(a[i], b[i]);
        a[i] -= temp;
        b[i] -= temp;
    }

    // Can be deficient in at most one material
    int count = 0;
    int needed = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            count++;
            needed = b[i];
            a.erase(a.begin() + i); // remove element a[i] = 0 from vector
        }
        if (count > 1) {
            cout << "NO" << endl;
            return;
        }
    }

    // check to make sure there are enough other elements to make the one b[i] > 0
    if (*min_element(a.begin(),a.end()) < needed) {
        cout << "NO" << endl;
        return;
    }




    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
