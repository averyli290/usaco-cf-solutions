/*
Problem link: https://codeforces.com/contest/2204/problem/D
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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;


void solve() {
    int n, e; cin >> n >> e;
    vector<bool> visited(n + 1, false);
    vector<int> parity(n + 1, -1);
    vector<vi> adj(n + 1, vi{});
    for(int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        // cout << x << " " << y << endl;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    function<int(int)> bfs = [&] (int src) {
        queue<pii> q;
        int ans0 = 0;
        int ans1 = 0;
        bool good = true;
        // debug(src);
        q.push({src, 0});
        while (!q.empty()) {
            auto [cur, curpar] = q.front();
            q.pop();
            visited[cur] = true;
            if (curpar == 0) ans0++;
            else ans1++;
            parity[cur] = curpar;
            for(int neig : adj[cur]) {
                // debug(neig);
                if (parity[neig] > -1 && parity[neig] == curpar) {
                    good = false;
                }
                if (!visited[neig]) {
                    q.push({neig, (curpar + 1) % 2});
                    visited[neig] = true;
                }
            }
        }
        // debug(ans0);
        // debug(ans1);
        return good ? max(ans0, ans1) : 0;
    };
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        if (!visited[i]) tot += bfs(i);
    }
    cout << tot << endl;
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
