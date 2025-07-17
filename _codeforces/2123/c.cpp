/*
Problem link: https://codeforces.com/contest/2123/problem/C
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

/*
make current max of suffix or min of prefix
*/

void solve() {
    int n; cin >> n;
    vi pref(n + 2, INT_MAX);
    vi suff(n + 2, 0);
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = min(a[i], pref[i]);
    }
    for(int i = n; i > 0; i--) {
        suff[i] = max(a[i - 1], suff[i + 1]);
    }
    string ans = "";
    for(int i = 1; i <= n; i++) {
        if (a[i - 1] == pref[i] || a[i - 1] == suff[i]) {
            ans += '1';
        }
        else ans += '0';
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
