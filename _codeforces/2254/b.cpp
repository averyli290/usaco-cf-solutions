/*
Problem link: https://codeforces.com/contest/2254/problem/B
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

/*
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<char, int>> a;
    int run = 1;
    for(int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            a.push_back({s[i - 1], run});
            run = 0;
        }
        run++;
    }
    a.push_back({s[n - 1], run});
    // for(auto [x, y] : a) {
    //     cout << x << " " << y << endl;
    // }
    int ans = sz(a);
    for(int i = 0; i < sz(a) - 2; i++) {
        if ((a[i].first == a[i+2].first) && a[i + 1].second == 1) {
            cout << ans - 2 << endl;
            return;
        }
    }
    for(int i = 1; i < sz(a) - 1; i++) {
        if (a[i].second == 1) {
            cout << ans - 1 << endl;
            return;
        }
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
