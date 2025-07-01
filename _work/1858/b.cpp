/*
Problem link: https://codeforces.com/contest/1858/problem/B
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<int> s(m);
    for(int i = 0; i < m; i++) { cin >> s[m]; }
    
    // middle
    int ans = 0;
    for(int i = 0; i < m - 2; i++) {
        if (s[i + 2] - s[i] <= n) {
            ans++;
        }
    }

    // first
    if (s[0] > n) {

    }

    // last

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
