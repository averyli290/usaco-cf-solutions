/*
Problem link: https://codeforces.com/contest/2167/problem/F
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
idea: for each node x, check how many nodes y in tree can be the root where x can be 
an LCA for a chosen set of nodes relative to y.

6 3
1 2
1 3
2 4
2 5
3 6
    1
   / \
  2   3
 / \   \
4  5   6


need:
at least k nodes in subtree

iterate over children and reroot and check above to see if it will contribute to those


must also check when root is in one of children
if (n - subtree_size[cur] < k), then we can check if root can be placed in children
for each child: if (sum of rest of children subtree sizes) + (n - subtree_size[cur] + 1) >= k
then this cur can be counted in an additional subtree_size[child] roots

*/

void solve() {
    ll n, k; cin >> n >> k;

    vector<vi> adj(n, vi{});
    vll subtree(n, 1ll);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    function<void(int,int)> dfs = [&] (int cur, int par) {
        for(int neig : adj[cur]) {
            if (neig != par) {
                dfs(neig, cur);
                subtree[cur] += subtree[neig];
            }
        }
    };

    dfs(0, -1);     // compute subtree sizes

    ll ans = 0ll;
    function<void(int,int)> dfs2 = [&] (int cur, int par) {
        if (n >= k) ans ++; // check if can root at cur
        if (par != -1 && subtree[cur] >= k) {    // check if can root at nodes not in subtree of cur (if not root)
            ans += n - subtree[cur];
        }

        // check if can root in subtrees of cur, not including cur itself as it has been checked above
        for(int neig : adj[cur]) {
            if (neig == par) continue;
            if (n - subtree[neig] >= k) {
                ans += subtree[neig];
            }
        }
        for(int neig : adj[cur]) {
            if (neig != par) dfs2(neig, cur);
        }
    };

    dfs2(0, -1);

    cout << ans << endl;

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


/*

Problem link:


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


6 3
1 2
1 3
2 4
2 5
3 6
    1
   / \
  2   3
 / \   \
4  5   6


need:
at least k nodes in subtree

iterate over children and reroot and check above to see if it will contribute to those


must also check when root is in one of children
if (n - subtree_size[cur] < k), then we can check if root can be placed in children
for each child: if (sum of rest of children subtree sizes) + (n - subtree_size[cur] + 1) >= k
then this cur can be counted in an additional subtree_size[child] roots


void solve() {
    ll n, k; cin >> n >> k;

    vector<vi> adj(n, vi{});
    vll subtree(n, 1ll);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    function<void(int,int)> dfs = [&] (int cur, int par) {
        for(int neig : adj[cur]) {
            if (neig != par) {
                dfs(neig, cur);
                subtree[cur] += subtree[neig];
            }
        }
    };

    dfs(0, -1);     // compute subtree sizes

    ll ans = 0ll;
    function<void(int,int)> dfs2 = [&] (int cur, int par) {
        if (n >= k) {
            ans += 1ll;
        }
        if(par != -1) {     
            if (n >= k) ans++;          // check if can root at cur
            if (subtree[cur] >= k) {    // check if can root at nodes not in subtree of cur
                ans += n - subtree[cur];
            }

            // check if can root in subtrees of cur, not including cur itself as it has been checked above
            for(int neig : adj[cur]) {
                if (neig == par) continue;
                if (n - subtree[neig] >= k) {
                    ans += subtree[neig];
                }
            }
        } else {
            // is root, only check subtrees no parent
            for(int neig : adj[cur]) {
                if (n - subtree[neig] >= k) {
                    ans += subtree[neig];
                }
            }
        }
        for(int neig : adj[cur]) {
            if (neig != par) dfs2(neig, cur);
        }
    };

    dfs2(0, -1);

    cout << ans << endl;

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

*/