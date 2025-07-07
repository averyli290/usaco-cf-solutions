/*
Problem link: https://codeforces.com/contest/1702/problem/G2
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

vector<vi> adj;
vector<unordered_set<int>> query_ids;
vector<bool> merged;      // query_id: merged mapping
vector<bool> ans;

void dfs(int cur, int par=-1) {
    unordered_map<int, int> cur_count;
    for(int neig : adj[cur]) {
        if (neig != par) {
            dfs(neig, cur);
        }
    }
    for(int neig : adj[cur]) {
        // check if query_ids
        if (neig != par) {
            for (int query_id : query_ids[neig]) {
                if (!ans[query_id]) continue;
                if (merged[query_id] && query_ids[cur].count(query_id) > 0) {
                    ans[query_id] = false;
                }
                cur_count[query_id]++;
                query_ids[cur].insert(query_id);
                if (cur_count[query_id] > 1) {
                    merged[query_id] = true;
                }
            }
        }
    }
    for(int neig : adj[cur]) {
        if (neig != par) {
            query_ids[neig].clear();
        }
    }
}

void solve() {
    int n; cin >> n;
    adj.assign(n + 1, vi{});
    query_ids.assign(n + 1, unordered_set<int>{});
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int q; cin >> q;
    merged.assign(q, false);
    ans.assign(q, true);
    for (int i = 0; i < q; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int v; cin >> v;
            query_ids[v].insert(i);
        }
    }
    dfs(1);
    for(int i = 0; i < q; i++) {
        if (ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
