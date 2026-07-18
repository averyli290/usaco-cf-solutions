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

/*
remove leaves
we can guarantee removing a leaf by using parity of distance from root
*/

vector<vi> adj;
vi depth;
queue<int> q;
void dfs(int cur, int par = -1, int d = 0) {
    if (sz(adj[cur]) == 1) q.push(cur);
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

    int ctr = 0;
    vi ans1;
    vi ans2;
    while(!q.empty()) {
        int cur = q.front();
        // debug(cur);
        // debug(depth[cur] % 2);
        q.pop();
        if (cur == n) continue; // dont delete n

        // delete cur
        if (depth[cur] % 2 == ctr % 2) {
            ctr++;
            ans1.push_back(1);
            ans2.push_back(0);
        }
        ans1.push_back(2);
        ans2.push_back(cur);
        ans1.push_back(1);
        ans2.push_back(0);
        ctr++;
        int par = adj[cur][0];
        adj[par].erase(find(all(adj[par]), cur));
        if (sz(adj[par]) == 1) q.push(par);
    }
    cout << sz(ans1) << endl;
    for(int i = 0 ; i < sz(ans1); i++) {
        if (ans1[i] == 1) cout << 1 << endl;
        else cout << 2 << " " << ans2[i] << endl;
    }
    cout << endl;
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
