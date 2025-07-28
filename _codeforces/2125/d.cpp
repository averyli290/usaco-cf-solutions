/*
Problem link: https://codeforces.com/contest/2125/problem/D
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
const long long MOD = 998244353;

struct iii{
    ll l;
    ll p;
    ll q;
};

ll inv(ll a) {
    return a <= 1 ? a : MOD - (MOD / a) * inv(MOD % a) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;

    map<ll, vector<iii>> mp;
    vll dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        mp[r].push_back({l,p,q});
        dp[0] = dp[0] * (q - p) % MOD * inv(q) % MOD;
    }


    for(int i = 1; i <= m; i++) {
        // ends at i
        for (int j = 0; j < sz(mp[i]); j++) {
            //cout << mp[i][j].p << endl;
            dp[i] += (dp[mp[i][j].l - 1] * mp[i][j].p % MOD * inv(mp[i][j].q)) % MOD * (mp[i][j].q) % MOD * inv(mp[i][j].q - mp[i][j].p) % MOD;
            dp[i] %= MOD;
        }
    }

    cout << dp[m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
