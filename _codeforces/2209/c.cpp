/*
Problem link: https://codeforces.com/contest/2209/problem/C
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
compare across
*/

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        if (query(i, n + i) == 1) {
            cout << "! " << i << endl;
            cout.flush();
            return;
        }
    }
    // one of (1, n+1) is 0
    // one of (2, n+2) is 0
    if (query(1, 2) == 0 && query(1, n + 2) == 0) cout << "! " << n+1 << endl;
    else cout << "! " << 1 << endl;
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
