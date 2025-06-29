/*
Problem link: https://codeforces.com/contest/2117/problem/F
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
cant have more than two leaves
find junction
take the short height leg, assign starting with either 1 or 2, this forces
an assignment on shorter and taller leg up to a certain depth until junction,
it will be one further on the taller when starting with 2 on shorter leg leaf.
the rest can be assigned however wanted.
if legs are same height, two choices, then two ways to assign leaves, everything
junction and above can be assigned however
*/

const int MOD = 1E9 + 7;

vector<vi> adj;

int h(int x) {
    int ret = 1;
    while (adj[x].size() > 0) {
        x = adj[x][0];
        ret++;
    }
    return ret;
}

void dfs(int cur, int par, vector<vi> &adj_v) {
    adj[par].push_back(cur);
    for (int neig : adj_v[cur]) {
        if (neig != par) {
            dfs(neig, cur, adj_v);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<vi> temp_adj = vector<vi>(n + 1, vi{});
    adj.assign(n + 1, vi{});
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        temp_adj[x].push_back(y);
        temp_adj[y].push_back(x);
    }
    int num_leaves = 0;
    for(int i = 2; i <= n; i++) {
        if (temp_adj[i].size() == 1) num_leaves++;
    }
    if (num_leaves > 2) {
        cout << 0 << endl;
        return;
    }
    dfs(1, 0, temp_adj);

    int ans = 0;

    int cur = 1;
    int top_h = 0;
    while (adj[cur].size() == 1) {
        cur = adj[cur][0];
        top_h++;
    }
    top_h++;

    //cout << cur << endl;

    if (adj[cur].size() == 0) { // 1 leaf
        ans = 1;
        for(int i = 0; i < n; i++) {
            ans = ans * 2 % MOD;
        }
        cout << ans << endl;
        return;
    }

    // 2 leaves
    int left = adj[cur][0]; int right = adj[cur][1];
    int l_h = h(left); int r_h = h(right);
    if (l_h > r_h) {
        swap(l_h, r_h);
        swap(left, right);
    }

    //cout << l_h << " " << r_h << endl;
    if (l_h == r_h) {
        ans = 2;
        //cout << top_h << endl;
        for(int i = 0; i < top_h; i++) {
            ans = ans * 2 % MOD;
        }
        cout << ans << endl; return;
    }

    // start with 1 on lower leaf
    int cur_ans = 1;
    for(int i = 0; i < n - 2 * l_h; i++) {
        cur_ans = cur_ans * 2 % MOD;
    }
    ans = (ans + cur_ans) % MOD;
    //cout << n << " " << l_h << endl;

    // start with 2 on lower leaf
    cur_ans = 1;
    for(int i = 0; i < n - (2 * l_h + 1); i++) {
        cur_ans = cur_ans * 2 % MOD;
    }
    ans = (ans + cur_ans) % MOD;
    //cout << cur_ans << endl;

    cout << ans << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
