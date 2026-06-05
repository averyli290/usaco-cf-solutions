/*
Problem link: https://codeforces.com/contest/1914/problem/F
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
dp?

1
|
5
2 3 4

1 2 1 1 3 3

1-5
|\
2 4
|
3-7
|
6
*/


void solve() {
    int n; cin >> n;
    vi p(n, -1);
    vector<vi> adj(n, vi{});
    vi dp(n, 0);
    vi subtree(n, 1);
    for(int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        p[i] = x;
        adj[x - 1].push_back(i + 1);
    }

    function<void(int, int)> dfs = [&] (int cur, int par) {
        for(int c : adj[cur]) {
            if (c != par) {
                dfs(c, cur);
                subtree[cur] += subtree[c];
            }
        }
    };

    function<int(int,int)> dfs2 = [&] (int cur, int rem) {  // rem to number of unmatched from above nodes
        if (subtree[cur] == 1) return 0;
        int maxval = 0;
        int maxidx = -1;
        for(int c : adj[cur]) {
            if (subtree[c] > maxval) {
                maxval = subtree[c];
                maxidx = c;
            }
        }
        // debug(cur);
        // debug(sz(adj[cur]));
        int val = subtree[cur] - 1 - subtree[maxidx];
        if ((subtree[maxidx] - rem) <= val) return (subtree[cur] - 1 - rem) / 2;
        return val + dfs2(maxidx, max(0, val + rem - 1));// pls clamp above 0 for the love of god
    };
    dfs(0, -1);
    // start with 0 unmatched in base case for root
    cout << dfs2(0, 0) << endl;

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
