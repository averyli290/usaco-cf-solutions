/*
Problem link: https://codeforces.com/contest/2144/problem/D
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

/*
9 81, 100000
*/

void solve() {
    ll n, y; cin >> n >> y;
    vll c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(all(c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}