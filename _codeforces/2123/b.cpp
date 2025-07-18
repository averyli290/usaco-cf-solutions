/*
Problem link: https://codeforces.com/contest/2123/problem/B
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
    int n, j, k; cin >> n >> j >> k;
    vi a(n);
    for(int i = 0; i < n;i++) cin >> a[i];
    if (k > 1) {
        cout << "YES" << endl;
        return;
    }
    if (a[j - 1] >= *max_element(all(a))) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
