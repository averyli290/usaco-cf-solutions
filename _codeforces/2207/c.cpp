/*
Problem link: https://codeforces.com/contest/2207/problem/C
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
    ll n, h; cin >> n >> h;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << h - a[0] << endl;
        return;
    }
    
    vll b(n);
    for(int i = 0; i < n; i++) {
        ll cur = h - a[i];
        ll curmax = a[i];
        for (int j = i - 1; j >= 0; j--) {
            curmax = max(curmax, a[j]);
            cur += h - curmax;
        }
        curmax = a[i];
        for (int j = i + 1; j < n; j++) {
            curmax = max(curmax, a[j]);
            cur += h - curmax;
        }
        b[i] = cur;
    }
    // for (ll &v : b) {
    //     cout << v << endl;
    // }

    ll ans = 0LL;
    for(int i = 0; i < n; i++) {
        ll curmax = a[i];
        int curmaxidx = i;
        for(int j = i + 1; j < n; j++) {
            if (curmax < a[j]) {
                curmax = a[j];
                curmaxidx = j;
            }
            ans = max(ans, b[i] + b[j] - b[curmaxidx]);
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