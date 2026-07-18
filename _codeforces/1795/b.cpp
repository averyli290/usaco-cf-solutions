/*
Problem link: https://codeforces.com/problemset/problem/1795/B
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
    int n, k; cin >> n >> k;
    vi l(51, 0), r(51, 0);
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        l[x]++; r[y]++;
    }
    if (l[k] > 0 && r[k] > 0) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
