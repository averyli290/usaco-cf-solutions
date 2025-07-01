/*
Problem link: https://codeforces.com/problemset/problem/1800/D
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = n - 1;
    for(int i = 1; i < n - 1; i++) {
        if (s[i - 1] == s[i + 1]) {
            ans--;
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
