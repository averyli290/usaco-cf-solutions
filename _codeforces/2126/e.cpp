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
    int n; cin >> n;
    vll p(n), s(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    vll a(n);
    for(int i = 0; i < n; i++) {
        a[i] = lcm(p[i], s[i]);
    }

    int cur = a[0];
    for(int i = 0; i < n; i++) {
        cur = gcd(cur, a[i]);
        if (cur != p[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cur = a[n - 1];
    for(int i = n - 1; i >= 0; i--) {
        cur = gcd(cur, a[i]);
        if (cur != s[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 1; i < n; i++) {
        if (p[i - 1] % p[i] != 0) {
            cout << "NO" <<endl;
            return;
        }
    }
    for(int i = n - 1; i > 0; i--) {
        if (s[i] % s[i - 1] != 0) {
            cout << "NO" <<endl;
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