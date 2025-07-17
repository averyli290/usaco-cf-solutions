/*
Problem link:
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
build like binary tree, everything to left is smaller, everything to right is larger, is possible
choose number based on size of left and right subtree

for each node, contribution = left subtree size * right subtree size
only works for 1/2 children

for a node with subtrees, contribution = 
cur subtree size * (all other subtree sizes added - cur subtree size)

if a node has three subtrees, only two pairs can work.
place the value of the node as close to middle as possible.
how to get largest sum?

*/

vll subtree_size;
vector<vi> adj;
void calcSubtrees(int cur) {
    subtree_size[cur]++;
    for(int neig : adj[cur]) {
        calcSubtrees(neig);
        subtree_size[cur] += subtree_size[neig];
    }
}

int dfs(int cur) {
    vector<ll> subtree_sizes;
    ll cur_ans = 0;
    ll ans = 0;
    for(int neig : adj[cur]) {
        subtree_sizes.push_back(subtree_size[neig]);
    }
    ll s1 = 0;
    ll s2 = 0;
    sort(all(subtree_sizes));
    for(int i = sz(subtree_sizes) - 1; i >= 0; i--) {
        if (s1 <= s2) {
            s1 += subtree_sizes[i];
        } else {
            s2 += subtree_sizes[i];
        }
    }

    ans += s1 * s2;
    for(int neig : adj[cur]) {
        ans += dfs(neig);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    adj.assign(n + 1, vi{});
    subtree_size.assign(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
        //adj[i].push_back(x);
    }
    calcSubtrees(1);
    int ans = dfs(1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
