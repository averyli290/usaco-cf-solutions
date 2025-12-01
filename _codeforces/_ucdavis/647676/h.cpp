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
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;


void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n);
    for (int i = 0 ;i < m ;i++) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }
    int a, b; cin >> a >> b;

    vector<bool> vis(n, false);
    vector<bool> possible(n, false);
    queue<int> q;
    q.push(a-1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vis[cur] = true;
        possible[cur] = true;
        for(int neig : adj[cur]) {
            if (!vis[neig]) q.push(neig);
        }
    }

    q.push(b-1);
    vis.assign(n, false);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (possible[cur]) {
            cout << "yes" << endl;
            cout << cur+1 << endl;
            return;
        }
        vis[cur] = true;
        for(int neig : adj[cur]) {
            if (!vis[neig]) q.push(neig);
        }
    }

    cout << "no" << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
