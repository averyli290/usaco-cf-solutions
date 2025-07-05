/*
Problem link: https://codeforces.com/contest/2078/problem/D
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

+ 9 x 2     1 1 -> 9 + 1
x 2 x 3     1 11 -> 1 + 22
+ 9 + 10    23 11 -> 9 + 10
x 2 + 1     42 11 -> 42 + 1

dp[i][j] = pair with greatest sum after going through gate i - 1
and choosing left (j = 0) or right (j = 1) for additional

dp[0][0] = {1, 1}
dp[0][1] = {1, 1}

*/

void solve() {
    int n; cin >> n;
    vector<pair<char, ll>> a(n);
    vector<pair<char, ll>> b(n);
    for(int i = 0; i < n; i++) {
        char c1, c2; ll x1, x2;
        cin >> c1 >> x1 >> c2 >> x2;
        a[i] = {c1, x1};
        b[i] = {c2, x2};
    }
    vll suffa(n + 1, 1LL);
    vll suffb(n + 1, 1LL);
    for(int i = n - 1; i >= 0; i--) {
        suffa[i] = suffa[i + 1];
        suffb[i] = suffb[i + 1];
        if (a[i].first == 'x') suffa[i] *= a[i].second;
        if (b[i].first == 'x') suffb[i] *= b[i].second;
    }

    int cura = 1;
    int curb = 1;
    for(int i = 0; i < n; i++) {
        ll add = 0;
        if (a[i].first == '+') add += a[i].second;
        else add += (a[i].second - 1) * cura;
        if (b[i].first == '+') add += b[i].second;
        else add += (b[i].second - 1) * curb;
        if (i == n - 1) {
            cura += add;
            continue;
        }

        if (a[i].first == '+')
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}