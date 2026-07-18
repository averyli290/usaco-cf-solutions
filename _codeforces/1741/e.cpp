/*
Problem link: https://codeforces.com/problemset/problem/1741/E
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
dp[i] = true is pref up to and including i is possible
store whether or not pref is possible in a set if u want
*/

void solve() {
    int n; cin >> n;
    set<int> s;
    s.insert(0);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (s.find(i - 1) != s.end()) {
            if (x + i <= n) s.insert(x + i);
        }
        if (s.find(i - x - 1) != s.end()) {
            s.insert(i);
        }
    }
    if (s.find(n) != s.end()) {
        cout << "YES" << endl;
        // debug(*s.find(n));
    }
    else cout << "NO" << endl;
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
