/*
Problem link: https://codeforces.com/contest/2131/problem/D
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
    int n; cin >> n;
    vector<vi> adj(n, vi{});
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (n == 2) {
        cout << 0 << endl;
        return;
    }
    
    int totleaves = 0;
    vi leavesct(n, 0);
    for(int i = 0; i < n; i++) {
        if (sz(adj[i]) == 1) {
            totleaves++;
            leavesct[adj[i][0]]++;
        }
    }
    cout << totleaves - *max_element(all(leavesct)) << endl;
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
