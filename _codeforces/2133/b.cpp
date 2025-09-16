/*
Problem link: https://codeforces.com/contest/2133/problem/B
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
    priority_queue<ll> g;
    for(int i = 0 ; i < n; i++) {
        ll x; cin >> x;
        g.push(x);
    }
    ll ans = 0;
    for(int i = 0 ; i < n - 1; i++) {
        ll a = g.top();
        g.pop();
        ll b = g.top();
        g.pop();
        ans += a;
        g.push(0);
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
