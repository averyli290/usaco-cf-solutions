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

/*
dp[v] = maximum shared value in subtree (including v after all operations)
*/

void solve() {
    int n; cin >> n;
    vi a(n + 1);
    vi p(n + 1);
    vector<vi> c(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++) {
        cin >> p[i];
        c[p[i]].push_back(i);
    }

    function<int(int)> dfs = [&] (int cur) {
        // debug(a[cur]);
        if (sz(c[cur]) == 0) return a[cur];
        int minval = INT_MAX;
        for(int child : c[cur]) {
            minval = min(minval, dfs(child));
        }
        // debug(minval);
        if (a[cur] >= minval) return min(a[cur], minval);
        return (minval - a[cur]) / 2 + a[cur];
    };

    if (sz(c[1]) == 0) cout << a[1];
    else {
        int minval = INT_MAX;
        for(int child : c[1]) {
            minval = min(minval, dfs(child));
        }
        // debug(minval);
        cout << a[1] + minval;
    }
    cout << endl;
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
