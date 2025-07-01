/*
Problem link: https://codeforces.com/contest/2117/problem/E
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;
    vector<bool> vis(2000001, false);

    if (a[n - 1] == b[n - 1]) {cout << n << endl; return; }

    for(int i = n - 2; i >= 0; i--) {
        // cases:
        // a_i=b_i
        // a_i=a_{i+1} or b_i=b_{i+1}
        // a_i or b_i has been seen at some point in i+2 onwards
        if (a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i+1] || vis[a[i]] || vis[b[i]]) {
            cout << i + 1 << endl;
            return;
        }
        vis[a[i + 1]] = true;
        vis[b[i + 1]] = true;
    }
    cout << 0 << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
