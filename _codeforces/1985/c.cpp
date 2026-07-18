/*
Problem link: https://codeforces.com/problemset/problem/1985/C
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll curmax = 0ll;
    ll cursum = 0ll;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cursum += a[i];
        curmax = max(a[i], curmax);
        if (cursum - curmax == curmax) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
