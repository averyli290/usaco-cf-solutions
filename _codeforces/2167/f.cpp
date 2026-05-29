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

dp[i][neig] = # of nodes in subtree excluding the one going down neig

need:
number of nodes in subtree >= k (including self), number of nodes in children subtrees < k
then, this node is counted for n - subtree_size[cur] + 1 roots (bc can use cur node as root)

must also check when root is in one of children
if (n - subtree_size[cur] < k), then we can check if root can be placed in children
for each child: if (sum of rest of children subtree sizes) + (n - subtree_size[cur] + 1) >= k
then this cur can be counted in an additional subtree_size[child] roots

*/

void solve() {
    int n; cin >> n;
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
