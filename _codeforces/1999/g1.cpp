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

int q(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int lo = 2;
    int hi = 999;
    while (lo + 1 < hi) {
        int diff = (hi - lo) / 3;
        int mid1 = lo + diff;
        int mid2 = lo + 2 * diff;
        int res = q(mid1, mid2);
        int p = mid1 * mid2;
        if (res == p) {
            lo = mid2 + 1;
        } else if (res == (mid1 + 1) * (mid2 + 1)) {
            hi = mid1;
        } else {
            lo = mid1 + 1;
            hi = mid2;
        }
    }
    if (lo == hi) cout << "! " << hi << endl;
    else {
        if (q(lo, lo) == lo * lo) cout << "! " << hi << endl;
        else cout << "! " << lo << endl;
        
    }
    cout.flush();
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