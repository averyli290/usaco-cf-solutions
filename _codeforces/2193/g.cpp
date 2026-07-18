/*
Problem link: https://codeforces.com/problemset/problem/2193/G
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
://

query leaf pairs (reduces by 2 each time)
binary search over the remaining

had to look at the editorial for the hint of dfs

dfs...? then can reuse previous information because the path has only unknowns
at the endpoints because if the path is longer than just 2, then it lies in already
queried nodes

lowkey knew i needed to query set pairs, but couldn't get the order right...

*/


int q(int u, int v) {
    cout << "? " << u + 1 << " " << v + 1 << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;

    vector<vi> adj(n, vi{});
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi winnipeg;
    function<void(int,int)> dfs = [&] (int cur, int par) {
        winnipeg.push_back(cur);
        for(int neig : adj[cur]) {
            if (neig != par) dfs(neig, cur);
        }
    };
    dfs(0, -1);

    int ans = winnipeg[n - 1];
    for(int i = 1; i < n; i+=2) {
        int u = winnipeg[i];
        int v = winnipeg[i - 1];
        if (q(u, v) == 1) {
            if (q(u, u) == 1) ans = u;
            else ans = v;
            break;
        }
    }
    cout << "! " << ans + 1 << endl;
    cout.flush();

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
