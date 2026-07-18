/*
Problem link: https://atcoder.jp/contests/awc0090/tasks/awc0090_c
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
    int n, m;
    cin >> n >> m;
    vi l(n), r(n), p(n), q(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
    }
    vector<array<int, 2>> adj(n, array<int, 2>);
    vi ct(n, 0);
    for(int i = 0;i < m; i++) {
        int u, v, b; cin >> u >> v >> b;
        u--; v--;
        adj[u].push_back({v, b});
        ct[v]++;
    }
    for(int i = 0; i < n; i++) {
        if (i != 1 && ct[i] != 1) {
            cout << "NO" << endl;
        }
        if (sz(adj[i]) > 2) {
            cout << "NO" << endl;
            return;
        }
        int ct1=0;
        int ct2=0;
        for(auto [a, b] : adj[i]) {
            if (b == 0) ct1++;
            else ct2++;
        }
        if (ct1 >= 2 || ct2 >= 0) {
            cout << "NO" << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
