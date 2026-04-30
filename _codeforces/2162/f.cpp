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

void solve() {
    int n, m; cin >> n >> m;
    int m2 = m;
    vi diff(n + 1, 0);
    // cout << endl;
    while(m2--) {
        int l, r; cin >> l >> r; l--; r--;
        // if (l == r) continue;
        diff[l]++;
        diff[r + 1]--;
    }

    // 0 2 1 0 
    vector<pii> a(n);
    int cur = 0;
    bool good = false;
    for(int i = 0; i < n; i++) {
        cur += diff[i];
        // cout << cur << " ";
        a[i] = {cur, i};
        if (cur == m) good = true;
    }
    // cout << endl;
    sort(all(a));
    if (good) reverse(all(a));
    vi ans(n);
    for(int i = 0; i < n; i++) {
        ans[a[i].second] = i;
    }
    for(int v : ans) {
        cout << v << " ";
    }
    cout << endl;
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
