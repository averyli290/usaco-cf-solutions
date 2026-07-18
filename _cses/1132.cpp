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

vector<vi> adj;
vector<int> dp1;        // stores largest path length
vector<int> dp2;        // stores second largest path length which does not use same vertex as dp1
vector<int> c;          // store child for max length path

// calc largest and second largest for each cur starting at cur and going downwards
void dfs1(int cur, int par=-1) {
    for(int neig : adj[cur]) {
        if (neig != par) {
            dfs1(neig, cur);
            if (dp1[neig] + 1 > dp1[cur]) {
                dp2[cur] = dp1[cur];        // neig cannot have contributed to dp1[cur]
                dp1[cur] = dp1[neig] + 1;
                c[cur] = neig;
            } else if (dp1[neig] + 1 > dp2[cur]) {
                dp2[cur] = dp1[neig] + 1;       // update second largest if can and largest not updated
            }
        }
    }
}

// dp1 and dp2 will now store largest and second largest paths overall (not just in subtree)
// now check paths through par for each cur, see if dp1 needs to be updated or dp2 needs to be updated
void dfs2(int cur, int par=-1) {
    // assume dp1 and dp2 of parent already calculated
    // assume that c[par] is also updated
    for(int neig : adj[cur]) {
        if (neig != par) {          // process thru the parent
            if (c[cur] == neig) {   // neig is the largest, use dp2[cur] to look at subtrees of 
                                    // parent excluding neig
                // best path outside neig's subtree is dp2[cur] + 1
                if (dp1[neig] < dp2[cur] + 1) {     // largest path length goes through parent
                    dp2[neig] = dp1[neig];          // update second largest path length, cant go through parent, so might
                                                    // as well choose largest path length in subtree
                    dp1[neig] = dp2[cur] + 1;       // update largest (goes thru parent)
                    c[neig] = cur;
                } else {
                    dp2[neig] = max(dp2[neig], dp2[cur] + 1);       // since best path goes through current subtree
                                                                    // update second largest path between old value (in own subtree)
                                                                    // or using path through the parent (has to use dp2)
                }
            } else {                // neig is not the largest, might as well go
                                    // through parent and find longer path from there
                dp2[neig] = dp1[neig];      // second largest path length cant go through parent, so might
                                            // as well choose largest path length in subtree
                dp1[neig] = dp1[cur] + 1;   // update largest path length to go through parent
                c[neig] = cur;
            }
            dfs2(neig, cur);
        }
    }
}

void solve() {
    int n; cin >> n;
    adj.assign(n, vi{});
    dp1.assign(n, 0);
    dp2.assign(n, 0);
    c.assign(n, 0);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(0);
    dfs2(0);
    for(int i = 0; i < n; i++) {
        cout << dp1[i] << " ";
    }
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
