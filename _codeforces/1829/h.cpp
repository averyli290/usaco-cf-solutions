/*
Problem link: https://codeforces.com/contest/1829/problem/H
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

const ll M = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vll dp(64, 0ll);
    for(int i = 0; i < n; i++) {
        vll newdp = dp;
        newdp[a[i]] += 1;
        newdp[a[i]] %= M;
        for(int j = 0; j < 64; j++) {
            newdp[j & a[i]] += dp[j];
            newdp[j & a[i]] %= M;
        }
        dp = newdp;
    }

    ll pog = 0ll;
    for(int i = 0; i < 64; i++) {
        if (__builtin_popcount(i) == k) {
            pog += dp[i];
            pog %= M;
        }
    }

    cout << pog << endl;

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
