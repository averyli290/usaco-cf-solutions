/*
Problem link: https://codeforces.com/contest/2144/problem/B
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    vi a(n);
    int ct = 0;
    int last = 0;
    vi vis(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            ct++;
            last = i;
        } else {
            vis[a[i] - 1] = 1;
        }
    }
    if (ct == 1)  {
        for(int i = 0; i < n; i++) {
            if (!vis[i]) {
                a[last] = i + 1;
                break;
            }
        }
    }


    int ans = 0;
    int left = -1;
    int right = -1;
    for(int i = 1; i <= n; i++) {
        if (a[i - 1] != i || a[i - 1] == 0) {
            left = i - 1;
            break;
        }
    }
    // cout << right << " " << left << endl;
    for(int i = n; i >= 1; i--) {
        if (a[i - 1] != i || a[i - 1] == 0) {
            right = i;
            break;
        }
    }
    cout << right - left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}