/*
Problem link: https://codeforces.com/contest/1829/problem/F
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
    vector<vi> adj(n, vi{});
    for(int i = 0;i < m; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[sz(adj[i])]++;
    }
    vector<pii> temp;
    for(auto [k, v] : mp) {
        if (k != 1) temp.push_back({v, k});
    }
    sort(all(temp));
    if (sz(temp) == 1) {
        cout << temp[0].second << " " << temp[0].second - 1 << endl;
    } else {
        // debug(1);
        // cout << temp[0].first << " " << temp[0].second << endl;
        // cout << temp[1].first << " " << temp[1].second << endl;
        cout << temp[0].second << " " << temp[1].second - 1 << endl;
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
