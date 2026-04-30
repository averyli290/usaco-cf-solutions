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
even and odd

1 2 3 4
1 2 3 4
*/

void solve() {
    int n, m; cin >> n >> m;
    vll a(n), x(m);
    vll evens;
    vll odds;
    ll tot = 0LL;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0) evens.push_back(a[i]);
        else odds.push_back(a[i]);
        tot += a[i];
    }
    for(int i = 0; i < m; i++) cin >> x[i];
    sort(all(evens));
    sort(all(odds));
    reverse(all(evens));
    reverse(all(odds));
    int e = 0; int o = 0;
    for(int i = 0; i < m; i++) {
        if (x[i] % 2 == 1 && e < sz(evens)) {
            if (e == 0) {
                tot -= evens[e];
                e++;
            } else if (evens[e] > 0) {
                tot -= evens[e];
                e++;
            }
        } else if (x[i] % 2 == 0 && o < sz(odds)) {
            if (o == 0) {
                tot -= odds[o];
                o++;
            } else if (odds[o] > 0) {
                tot -= odds[o];
                o++;
            }
        }
    }
    cout << tot << endl;
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
