/*
Problem link: https://codeforces.com/contest/2244/problem/F
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
https://www.youtube.com/watch?v=IbmHJ4Ynqzk


check that subtree has a continuous interval up to cyclic permutation
return range that subtree contains in dfs
*/

void solve() {
    int n; cin >> n;
    vector<vi> adj(n, vi{});
    vi par(n, -1);
    vi a(n);
    for(int i = 1; i < n; i++) {
        int x; cin >> x; x--;
        par[i] = x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ok = true;
    function<pii(int)> dfs = [&] (int cur) {
        // debug(cur);
        vector<pii> ranges;
        if (a[cur] > 0) return pii{a[cur],a[cur]};
        for(int neig : adj[cur]) {
            // debug(neig);
            if (neig != par[cur]) {
                ranges.push_back(dfs(neig));
            }
        }
        // check cyclic permutation by finding min first
        int lo = n;
        int startidx = -1;
        int r = sz(ranges);
        for(int i = 0; i < r; i++) {
            if (ranges[i].first < lo) {
                lo = ranges[i].first;
                startidx = i;
            }
        }
        // int lo = ranges[startidx].first;
        int hi = ranges[startidx].second;
        for(int i = 1; i < r; i++) {
            if (ranges[(startidx + i) % r].first != hi + 1) {
                ok = false;
                return pii{-1,-1};
            }
            hi = ranges[(startidx + i) % r].second;
        }
        return pii{lo,hi};
    };
    dfs(0);
    if (ok) cout << "yes" << endl;
    else cout << "no" << endl;
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
