/*
Problem link: https://codeforces.com/group/eH5P3JtXri/contest/686582/problem/B
*/

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
19 prime numbers less than 70
bitmask to represent prime factorization, 0 means even power, 1 means odd power
dp[bitmask] = number of products which multiply to 

cur_bitmask = bitmask of cur elt
dp[other_bitmask] += dp[other_bitmask ^ cur_bitmask]      // by symmetry, can add 1 to all
dp[0] += dp[cur_bitmask]
dp[cur_bitmask] += dp[0]
*/

int factors[19] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
    41, 43, 47, 53, 59, 61, 67
}; 

ll MOD = 1E9+7;


int bm(int x) {
    int res = 0b0;
    for(int i = 0; i < 19; i++) {
        int f = factors[i];
        int ct = 0;
        while (x % f == 0) {
            x /= f;
            ct++;
        }
        if (ct % 2 == 1) res |= (1 << i);
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vll dp(1 << 19, 0LL);
    vector<bool> vis(1 << 19, false);
    set<int> upd;
    upd.insert(0);
    dp[0] = 1LL;
    set<int> cur;
    cur.insert(0);
    for (int i = 0; i < n; i++) {
        int cur_bitmask = bm(a[i]);

        for(int b1 : upd) {
            if(vis[b1]) continue;
            ll v = dp[b1];
            // debug(b1);
            // debug(v);
            int b2 = b1 ^ cur_bitmask;
            ll vnew = (v + dp[b2]) % MOD;
            dp[b1] = vnew;
            dp[b2] = vnew;
            vis[b1] = true;
            vis[b2] = true;
            upd.insert(b2);
        }
        vis.assign(1 << 19, false);
    }
    cout << dp[0] - 1 << endl;
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
