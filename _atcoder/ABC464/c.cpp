/*
Problem link:
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
    vi ct(n, 0);
    vector<vector<pii>> d(m, vector<pii>{});
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int a, di, b; cin >> a >> di >> b;
        a--; di--; b--;
        if (di == 0) {
            if (ct[b] == 0) cur++;
            ct[b]++;
        } else {
            if (ct[a] == 0) cur++;
            ct[a]++;
        }
        if (di > 0) d[di].push_back({a, b});
    }
    for(int i = 0; i < m; i++) {
        for(auto [from, to] : d[i]) {
            if (ct[from] == 1) cur--;
            ct[from]--;
            if (ct[to] == 0) cur++;
            ct[to]++;
        }
        cout << cur << endl;
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
