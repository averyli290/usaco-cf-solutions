/*
Problem link: https://codeforces.com/contest/2132/problem/E
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
    int n, m, q; cin >> n >> m >> q;
    vll a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(all(a), greater<ll>());
    sort(all(b), greater<ll>());
    
    vll prefa(n + 1, 0ll);
    vll prefb(n + 1, 0ll);

    for(int i = 0; i < n; i++) prefa[i + 1] = prefa[i] + a[i];
    for(int i = 0; i < m; i++) prefb[i + 1] = prefb[i] + b[i];

    vll ans(n + 1, 0ll);
    for(int i = 0; i < n; i++) {
    }

    while(q--) {
        int x, y, z; cin >> x >> y >> z;
        // cout << prefa[x] + prefb[y] << endl;
        cout << ans[z] << endl;
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
