/*
Problem link: https://codeforces.com/contest/2183/problems/D
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

void solve() {
    int n; cin >> n;
    vector<vi> adj(n+1);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    vector<bool> vis(n + 1, false);
    vi depth(n+1, 0);
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        vis[cur] = true;
        for (int neig : adj[cur]) {
            if (!vis[neig]) {
                depth[neig] = depth[cur] + 1;
                q.push(neig);
            }
        }
    }
    map<int, int> mp;
    for(int i = 1; i < n + 1; i++) {
        mp[depth[i]]++;
    }
    int ans = 2;
    for(auto [k, v] : mp) {
        ans = max(ans, v);
    }
    for(int i = 1; i < n + 1; i++) {
        if (i == 1) ans = max(ans, sz(adj[i]) + 1);
        else ans = max(ans, sz(adj[i]));
    }
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
