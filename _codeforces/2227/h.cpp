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


/*

if parity of remaining to be matched is even add together
(total of children + total unmatched lengths of children + number of remaining to match)
unmatched length = 0

if parity of remaining is odd 
(total of children + total unmatched lengths of children (excluding largest) + number of remaining to match)
unmatched length = (max unmatched length of children) + 1

at each subtree, keep track of total cost to match and
cost of remaining length to match (want to maximize this to min 
the total cost)

*/

vector<vi> adj;
map<pll, pll> memo; // to keep between calculations

pll rec(int cur, int par) {
    if (sz(adj[cur]) == 1) {
        return pll{0LL, 1LL};
    }
    ll cur_cost = 0LL;
    vll rem;
    for(int child : adj[cur]) {
        if (child == par) continue;
        pll check = {child, cur};
        pll retval;
        if (memo.find(check) != memo.end()) retval = memo[check];
        else retval = rec(child, cur);
        auto [child_cost, child_rem] = retval;
        memo[check] = retval;
        cur_cost += child_cost;
        if(child_rem > 0LL) rem.push_back(child_rem);
    }
    if (sz(rem) % 2 == 0) {
        for(ll v : rem) cur_cost += v;
        return pll{cur_cost, 0LL};
    } else {
        ll temp = 0LL;
        for(ll v : rem) {
            cur_cost += v;
            temp = max(v, temp);
        }
        cur_cost -= temp;
        return pll{cur_cost, temp + 1};
    }
}

void solve() {
    int n; cin >> n;
    memo.clear();
    adj.clear();
    adj.resize(n + 1, vi{});
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int root = 1;
    while (sz(adj[root]) <= 1) root++;
    ll ans = rec(root, -1).first;
    
    // calculate for multiple roots to find answer, can ignore leaves and
    // nodes with deg = 2 because splitting on normal path doesn't help
    for(int root = 1; root <= n; root++) {
        if (sz(adj[root]) > 2) {
            ans = min(ans, rec(root, -1).first);
        }
    }
    cout << ans << endl;

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
