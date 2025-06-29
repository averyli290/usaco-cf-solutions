/*
Avery Li
5/1/2025
Problem link: https://codeforces.com/contest/2108/problem/C
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a;
    int temp;
    cin >> temp;
    a.push_back(temp);
    int c = 0;
    for (int i = 1; i < n; i++) {
        cin >> temp;
        if (temp != a[c]) {
            c++;
            a.push_back(temp);
        }
    }
    if (a.size() == 1) {
        cout << 1 << endl;
        return;
    }
    int ans = 0;

    for(int i = 0; i < a.size(); i++) {
        if (i == 0) {
            if (a[i] > a[i + 1]) {
                ans++;
            }
        } else if (i == a.size() - 1) {
            if (a[i] > a[i - 1]) {
                ans++;
            }
        } else if (i > 0 && i < a.size() - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]) {
            ans++;
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
