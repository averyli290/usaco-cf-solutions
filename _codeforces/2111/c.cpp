/*
Problem link: https://codeforces.com/contest/2111/problem/C
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
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll left = 0;
    ll right = 1;
    ll ans = INF;
    while (right < n) {
        if (a[right] != a[right - 1]) {
            ans = min(ans, (n - (right - left)) * a[left]);
            left = right;
        }
        right++;
    }
    ans = min(ans, (n - (right - left)) * a[left]);
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
