/*
Problem link:
*/

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
[l, r], r - l = d
p

a <= l
b >= r

maximize a * (x - l) + b * (r - x)
if (a > b) x = r
if (a < b) x = l


6 5

6d

minimum must lie on a given value in the a[] array

*/

void solve() {
    int n;
    ll l, r; cin >> n >> l >> r;
    vll a(n);
    ll baseans = 0LL;
    vll centers;
    ll numless = 0LL;
    ll nummore = 0LL;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = x;
        if (x <= l) {
            baseans += l - x;
        } else if (x >= r) {
            baseans += x - r;
        } else {
            centers.push_back(x);
        }
    }
    // calc at endpoints manually
    ll ans = LLONG_MAX;
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        cur += abs
    }


    // sort(all(b));
    // cout << "b: ";
    // for(auto v : b)  {
    //     cout << v << " ";
    // }
    // cout << endl;

    // n = sz(b);
    // ll cur = 0LL;
    // for(int i = 1; i < n; i++) {
    //     cur += b[i] - l;
    // }
    // b.push_back(r);
    // // debug(cur);
    // ll ans = LLONG_MAX;
    // debug(baseans);

    // for (int i = 0; i < n-1; i++) {
    //     // move from b[i] center to b[i + 1]
    //     // debug(i);
    //     // debug(b[i + 1] - b[i]);
    //     // debug((i) * (b[i + 1] - b[i]));
    //     // debug(n - 1 - i);
    //     // debug((n - 1 - i) * (b[i + 1] - b[i]));
    //     debug(numless);
    //     debug(nummore);
    //     numless++;
    //     nummore--;
    //     cur += numless*(b[i + 1] - b[i]);
    //     cur -= nummore*(b[i + 1] - b[i]);
    //     ans = min(cur, ans);

    // }
    // if (ans == LLONG_MAX) cout << baseans << endl;
    // else cout << ans + baseans << endl;


    // vll pref(n + 2, 0LL);
    // vll suff(n + 2, 0LL);
    // for(int i = 1; i <= n; i++) {
    //     pref[i] = pref[i - 1] + (b[i - 1] - l);
    // }
    // for(auto v : pref)  {
    //     cout << v << " ";
    // }
    // cout << endl;
    // for(int i = n; i >= 1; i--) {
    //     suff[i] = suff[i + 1] + (r - b[i - 1]);
    // }
    // for(auto v : suff)  {
    //     cout << v << " ";
    // }
    // cout << endl;
    // debug(baseans);
    // ll ans = LLONG_MAX;
    // for(int i = 0; i < n + 1; i++) {
    //     ll curans = baseans;
    //     if (i > 0) curans += pref[i - 1];
    //     if (i < n + 2) curans += suff[i + 1];
    //     debug(i);
    //     debug(pref[i - 1]);
    //     debug(suff[i + 1]);
    //     // ans = max(ans, baseans + pref[i - 1] + suff[i + 1]);
    //     ans = min(ans, curans);
    // }
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
