/*
Problem link: https://codeforces.com/contest/2154/problem/D
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
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;

vector<vi> adj;
vi depth;
void dfs(int cur, int par = -1, int d = 0) {
    depth[cur] = d;
    for (int neig : adj[cur]) {
        if (neig != par) dfs(neig, cur, d + 1);
    }
}

void solve() {
    int n; cin >> n;
    adj.assign(n + 1, vi{});
    depth.assign(n + 1, 0);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);

    stack<int> curpath;
    vector<bool> vis(n + 1, false);
    curpath.push(1);
    while(true) {
        int cur = curpath.top();
        vis[cur] = true;
        if (cur == n) break;

        for(int neig : adj[cur]) {
            if (!vis[neig]) {
                curpath.push(neig);
                continue;
            }
        }
        // none found
        curpath.pop();
    }

    vector<bool> to_remove_bool(n + 1, true);
    while (!curpath.empty()) {
        to_remove_bool[curpath.top()] = false;
        curpath.pop();
    }

    vector<int> to_remove;
    for(int i = 1; i <= n; i++) {
        if (to_remove_bool[i]) to_remove.push_back(i);
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
