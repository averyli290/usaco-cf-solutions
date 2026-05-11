

// #include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <exception>
#include <functional>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <random>
#include <stdexcept>
#include <typeinfo>
#include <utility>

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
    int n, q; cin >> n >> q;
    vector<vector<pair<int, ll>>> adj(n + 1, vector<pair<int, ll>>{});
    vi a(n + 1);
    ll tot = 0LL;
    vector<map<int, ll>> vmap(n + 1, map<int, ll>{});
    vi par(n + 1, 0);
    map<pii, ll> costs;



    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++){
        int x, y, c; cin >> x >> y >> c;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
        costs[pii{x,y}] = c;
        costs[pii{y,x}] = c;
        if (a[x] != a[y]) tot += c;
    }

    // use dfs to update cost based on children in constant time (swap between colors)
    // and update only one parent in constant time
    // instead of having to iterate through all neighbors

    function<void(int, int)> dfs = [&](int cur, int p) {
        for(auto [neig, cost] : adj[cur]) {
            if (neig == p) continue;
            par[neig] = cur;
            vmap[cur][a[neig]] += cost;
            dfs(neig, cur);
        }
    };

    // debug(tot);

    dfs(1, 0);
    
    while(q--) {
        int v, x; cin >> v >> x;
        if (x == a[v]) {
            cout << tot << endl;
            continue;
        }

        if (v != 1) {
            int c = costs[pii{par[v],v}];
            vmap[par[v]][a[v]] -= c;
            vmap[par[v]][x] += c;
            if (a[par[v]] != a[v] && x == a[par[v]]) tot -= c;
            else if (a[par[v]] == a[v] && x != a[par[v]]) tot += c;
        }


        tot += vmap[v][a[v]];
        tot -= vmap[v][x];
        a[v] = x;

        cout << tot << endl;

    }


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