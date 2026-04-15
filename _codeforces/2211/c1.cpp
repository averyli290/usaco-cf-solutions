/*
Problem link: https://codeforces.com/contest/2218/problem/E
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
check if the current subarray has a element not in the subarray of a
*/

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    vi b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    set<int> cur;
    set<int> curb;
    for(int i = 0; i < k; i++) {
        cur.insert(a[i]);
    }
    for(int i = 0; i < k; i++) {
        if (cur.find(b[i]) == cur.end()) {
            cout << "NO" << endl;
            return;
        }
        if (b[i] >= 0 && curb.find(b[i]) != curb.end()) {
            cout << "NO" << endl;
            return;
        }
        if (b[i] >= 0) curb.insert(b[i]);
    }
    for(int i = 0; i < n - k; i++) {
        cur.erase(a[i]);
        cur.insert(a[i + k]);
        curb.erase(b[i]);
        if (b[i] != -1 && cur.find(b[i]) != cur.end() ||
            b[i + k] != -1 && cur.find(b[i + k]) == cur.end()) {
            cout << "NO" << endl;
            return;
        }
        if (b[i + k] >= 0 && curb.find(b[i + k]) != curb.end()) {
            cout << "NO" << endl;
            return;
        }
        curb.insert(b[i + k]);
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
