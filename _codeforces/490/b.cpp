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
92 7 31 141 5
92 31
0 7
31 5
7 141
141 0

0 7 141 0

92 31 5

1 2 3 4 5
0 2
1 3
2 4
3 0

0 2
1 3
2 0
*/

void solve() {
    int n; cin >> n;
    map<int, int> mp, mp2;
    map<int, bool> vis;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        mp[x] = y;
        mp2[y] = x;
        vis[x] = false;
        vis[y] = false;
    }
    vi a;
    int cur = 0;
    while (mp.find(cur) != mp.end()) {
        vis[cur] = true;
        cur = mp[cur];
        if (cur == 0) break;
        a.push_back(cur);
    }
    vis[0] = true;

    map<int, int> val;
    function<void(int,int)> dfs = [&] (int cur, int t) {
        if (cur == 0) return;
        vis[cur] = true;
        val[cur] = t;
        if (!vis[mp[cur]]) dfs(mp[cur], t + 1);
        if (!vis[mp2[cur]]) dfs(mp2[cur], t - 1);
    };
    for(auto[k, v] : vis) {
        if (!v) {
            dfs(k, 0);
            break;
        }
    }
    int minval = INT_MAX;
    int start = -1;
    for(auto [k, v] : val) {
        // debug(k);
        // debug(v);
        if (v < minval) {
            start = k;
            minval = v;
        }
    }
    vi b;
    cur = start;
    b.push_back(cur);
    while (mp.find(cur) != mp.end()) {
        cur = mp[cur];
        if (cur == 0) break;
        b.push_back(cur);
    }

    for(int i = 0; i < sz(a); i++) {
        if (b[i] != 0) cout << b[i] << " ";
        if (a[i] != 0) cout << a[i] << " ";
    }
    if (sz(b) > sz(a)) {
        cout << b.back();
    }
    cout << endl;
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
