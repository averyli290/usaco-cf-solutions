/*
Problem link: https://codeforces.com/contest/2130/problem/D
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
mirror will always increase value of current, make everything after an inversion
*/

void solve() {
    int n; cin >> n;
    vi p(n);
    set<int> after;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int ans = 0;
    //cout << "N: " << n << endl;
    after.insert(p[0]);
    int prev = p[0];
    for(int i = 1; i < n; i++) {
        // int amt1 = distance(after.upper_bound(p[i]), after.end());
        // int amt2 = distance(after.upper_bound(2 * n - p[i]), after.end());
        if (p[i] < p[0]) {
            after.insert(2 * n - p[i]);
            ans += distance(after.upper_bound(2 * n - p[i]), after.end());
            prev = 2 * n - p[i];
        } else {
            after.insert(p[i]);
            ans += distance(after.upper_bound(p[i]), after.end());
            prev = p[i];
        }
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