/*
Problem link: https://codeforces.com/contest/1829/problem/C
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
    int n;
    cin >> n;
    vll a(n);
    ll m1 = INT_MAX;
    ll m2 = INT_MAX;
    ll ans = INT_MAX;
    for(int i = 0; i< n; i++) {
        cin >> a[i];
        string s;
        cin >> s;
        if (s[0] == '1' && s[1] == '1') ans = min(ans, a[i]);
        else if (s[0] == '1' && s[1] == '0') m2 = min(m2, a[i]);
        else if (s[1] == '1' && s[0] == '0') m1 = min(m1, a[i]);
    }
    ans =  min(ans, m1 + m2);
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    
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
