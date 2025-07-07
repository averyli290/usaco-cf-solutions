/*
Problem link: https://codeforces.com/contest/2065/problem/F
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

/*
if there exists a nontrivial simple path which satisfies,
then there exists one of length 3 or less
has to include 11 or 101, which itself is nontrivial simple path which works

for each vertex, maintain map of what values are next to it
*/

vector<vi> adj;
vector<map<int, int>> dist_1;
vi a;

void solve() {
    int n; cin >> n;
    adj.assign(n, vi{});
    a.assign(n, 0);
    dist_1.assign(n, map<int, int>{});
    vector<vi> b(n, vi{});
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]].push_back(i);
    }
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        dist_1[x][a[y]]++;
        dist_1[y][a[x]]++;
    }
    vi ans(n, 0);
    for(int i = 0; i < n; i++) {
        int target_value = i;
        for (int src : b[i]) {
            for (int neig : adj[src]) {
                if (a[neig] == target_value) { // distance 1 (11)
                    ans[i] = 1;
                    break;
                }
                if (dist_1[neig][target_value] >= 2) {    // distance 2 (101, 0 is neighbor, must have at least 2 of target value near it)
                    ans[i] = 1;
                    break;
                }
            }
        }
    }
    for(int v : ans) {
        cout << v;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
