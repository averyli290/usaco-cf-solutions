/*
Problem link: 
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 51;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((a[i] - a[j]) % 2 == 0) {
                ans = min(ans, i + (n - j - 1));
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
