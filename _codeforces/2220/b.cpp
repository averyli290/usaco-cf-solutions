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
2 4
1 3
1 0

2 2 4
0 1 1
1 0 2
0 1 3
1 0 0
0 1 1


2

0 1 1 1 0 1
*/


void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    // vector<pll> runs
    for(int i = 0; i < n; i++) cin >> a[i];

    // int consec_max = 1;
    int cur = 1;

    int threshold = m;
    for(int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) cur++;
        else {
            cur = 0;
            threshold = (a[i - 1] - a[i] + m) % m;
        }
        if (cur > threshold) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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
