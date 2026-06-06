/*
Problem link: https://codeforces.com/contest/2184/problem/F
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


/*
1 2
1 3
3 4
3 5
1 6
1 7

   7-1-6
    / \
   2   3
      / \
     4   5
*/

void solve() {
    int n; cin >> n;
    
    vi numleaves(n, 0);
    vector<vi> adj(n, vi{});
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    function<void(int, int)> dfs = [&] (int cur, int par) {
        if (sz(adj[cur]) == 1) {
            numleaves[cur] = 1;
            return;
        }
        for(int neig : adj[cur]) {
            if (neig != par) {
                dfs(neig, cur);
                numleaves[cur] += numleaves[neig];
            }
        }
    };

    dfs(0, -1);

    bool done = false;
    // array<int, 3>; mod 0, 1, 2 booleans
    function<array<int, 3>> dfs2 = [&] (int cur, int par) {
        // dp it up
        array<int, 3> ret = {0,0,0};
        // use
        
        // keep
    };

    dfs2(0, -1);
    if (!done) cout << "NO" << endl;

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
