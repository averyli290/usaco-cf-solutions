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
    
    vector<vi> adj(n, vi{});
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // array<bool, 3>; mod 0, 1, 2 booleans if can shake mod x amount of moves at node cur
    function<array<bool, 3>(int,int)> dfs2 = [&] (int cur, int par) {
        // dp it up
        int temp = -1;
        array<bool, 3> dp = {false, false, false};
        for(int neig : adj[cur]) {
            if (neig != par) {
                array<bool, 3> res = dfs2(neig, cur);
                array<bool, 3> dpnew = {false, false, false};
                if (temp == -1) {
                    temp = 1;
                    dpnew = res;
                } else {
                    // apply next child to see what possibile combinations there are
                    for(int i = 0; i < 3; i++) {
                        for(int j = 0; j < 3; j++) {
                            if (res[i] && dp[j]) dpnew[(i + j) % 3] = true;
                        }
                    }
                }
                dp = dpnew;
            }
        }
        dp[1] = true;       // can always shake all leaves in 1
        return dp;
    };

    array<bool, 3> wahoo = dfs2(0, -1);
    if (wahoo[0]) cout << "YES" << endl;
    else cout << "NO" << endl;


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
