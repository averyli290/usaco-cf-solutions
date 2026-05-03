
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
const long long MOD = 998244353;

/*
consecutive groups of 4 starting at 4i xor to 0 
*/

void solve() {
    ll n, x; cin >> n >> x;
    ll left = x / 4;
    ll right = max(0LL, (n / 4 * 4 - (x + 3) / 4 * 4) / 4 + 1);
    ll ans = (left * right) % MOD;
    left = (x + 2) / 4;
    ll t0 = 2;
    ll t1 = x;
    if (t1 >= 2) {
        while((t1 % 4) != 2) {
            t1--;
        }
        left = (t1 - t0) / 4 + 1;
    } else {
        left = 0LL;
    }
    while(t0 % 4 != 1) t0++;
    t1 = n;
    while(t1 % 4 != 1) t1--;
    right = (t1 - t0) / 4 + 1;
    // cout << (x + 3) / 4 * 4 << endl;
    // debug(n / 4 * 4);
    // debug((x + 3) / 4 * 4);
    // debug(left);
    // debug(right);
    // left = (x-2) / 4;
    // right = (n - 2) / 4 * 4 - (x - 2) / 4;
    // debug(ans);
    // ans = (ans + (left * right)) % MOD;
    // debug(ans);
    debug(left);
    debug(right);
    debug(t0);
    debug(t1);
    ans = (ans + (left * right)) % MOD;
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