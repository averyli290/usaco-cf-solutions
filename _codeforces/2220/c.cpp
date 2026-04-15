/*
Problem link: https://codeforces.com/contest/2220/problem/B
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

make min(m, n) by min(m, n) grid
then, filling in the rest takes at most max(m, n) - min(m, n)
straight pieces (place them all on one edge to make that edge length max(m, n),
and fill the rest with same orientation pieces)

2mn + m + n = p + 2q

2mn + m + n = tot
2mn + n = tot - m
n = (tot - m) / (2m + 1)

*/


void solve() {
    ll p, q; cin >> p >> q;
    ll tot = p + 2 * q;
    
    for (ll m = 1; m * m <= tot; m += 1) {
        ll n = (tot - m) / (2 * m + 1);
        if (2 * m * n + m + n == tot) {
            if (p >= max(m, n) - min(m, n)) {
                cout << m << " " << n << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
