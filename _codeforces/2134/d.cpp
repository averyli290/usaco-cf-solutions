/*
Problem link: https://codeforces.com/contest/2134/problem/D
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

a-a-a-a-a-a-a-a
          |
          a
          |
          a

*/


void solve() {
    int n; cin >> n;
    vector<vi> adj(n + 1, vi{});
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool good = true;
    int max_deg = 0;
    for(int i = 1; i <= n; i++) {
        int s = sz(adj[i]);
        if (s > 2) {
            good = false;
        }
        max_deg = max(max_deg, s);
    }
    if (good) {
        cout << -1 << endl;
        return;
    }
    cout << "other" << endl;
    for(int i = 1; i <= n; i++) {
        if (sz(adj[i]) == max_deg) {
            for (int neig : adj[i]) {

            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
