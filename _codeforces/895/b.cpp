/*
Problem link: https://codeforces.com/contest/895/problem/B
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


void solve() {
    ll n, x, k; cin >> n >> x >> k;
    vll a(n);
    vll b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(all(b));

    ll ans = 0LL;

    for(int i = 0; i < n; i++) {
        // bin search for the right idx on sorted b array
        ll left = a[i];
        ll lower = max(a[i], ((a[i] - 1) / x) * x + (x * k));
        ll upper = max(lower, ((a[i] - 1) / x) * x + (x * k) + (x - 1));
        auto ptr1 = lower_bound(b.begin(), b.end(), lower);
        auto ptr2 = upper_bound(b.begin(), b.end(), upper);
        // debug(lower);
        // debug(upper);
        // debug(ptr2-ptr1);
        // debug(*ptr1 % x);

        // boundary and edge checking when k = 0 to not include if endpoints are divisible
        if (k == 0 && (*ptr1 % x == 0 && ptr1 != b.begin() || *(ptr2-1) % x == 0 && ptr2 != b.end())) continue;
        ans += (ll) (ptr2-ptr1);
    }
    cout << ans << endl;

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
