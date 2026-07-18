/*
Problem link: https://codeforces.com/contest/1826/problem/E
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
    int n, m; cin >> n >> m;
    vll p(n);
    vector<vi> r(m, vi(n, 0));
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> r[i][j];
        }
    }
    vll dp(n);
    for(int i = 0; i < n; i++) {
        dp[i] = p[i];
        for(int j = 0; j < i; j++) {
            bool poss = true;
            for(int k = 0; j)
        }
    }
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
