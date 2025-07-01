/*
Problem link: https://codeforces.com/contest/2006/problem/A
*/

#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

/*
if root is fixed only depends on whether the leaves are 0 or 1

if root is 1:
    if leaf is 0, score of 1
    if leaf is 1, score of 0
if root is 0:
    if leaf is 0, score of 0
    if leaf is 1, score of 1

if leaf0 == leaf1, stall marking root until have to
if leaf0 != leaf1, immediately mark root to get greater value

after, mark leaves to get max value

*/

vector<vi> edges;
vector<vi> c;
string s;

void dfs(int cur, int par = -1) {
    for (auto neig : edges[cur]) {
        if (neig != par) {
            c[cur].push_back(neig);
            dfs(neig, cur);
        }
    }
}

void solve() {
    int n; cin >> n;
    edges.assign(n + 1, vi{});
    c.assign(n + 1, vi{});
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    cin >> s;
    dfs(1);
    int leaf0 = 0;
    int leaf1 = 0;
    int leaf2 = 0;
    int other_not_colored = 0;
    for (int i = 1; i <= sz(s); i++) {
        if (sz(c[i]) == 0) {
            if (s[i - 1] == '?') leaf2++;
            else if (s[i - 1] == '0') leaf0++;
            else leaf1++;
        } else if (s[i - 1] == '?' && i != 1) other_not_colored++;
    }
    bool root_colored = !(s[0] == '?');
    // cout << "root colored: " << (root_colored ? 1 : 0) << endl;
    // cout << "leaf0: " << leaf0 << endl;
    // cout << "leaf1: " << leaf1 << endl;
    // cout << "leaf2: " << leaf2 << endl;
    // cout << "other: " << other_not_colored << endl;
    if (root_colored) {
        if (s[0] == '0') cout << leaf1 + (leaf2 + 1) / 2 << endl;
        else cout << leaf0 + (leaf2 + 1) / 2 << endl;
        return;
    }
    if (leaf0 == leaf1) {
        if (other_not_colored % 2 == 1) {
            cout << leaf0 + (leaf2 + 1) / 2 << endl;
        } else {
            cout << leaf0 + leaf2 / 2 << endl;
        }
        return;
    }
    int ans = max(leaf0, leaf1);    // mark root
    ans += leaf2 / 2;
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
