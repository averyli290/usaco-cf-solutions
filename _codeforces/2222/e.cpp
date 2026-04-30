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

int q1(int x) {
    cout << "I " << x << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

int q2(int x) {
    cout << "Q " << x << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    ll n; cin >> n;
    
    ll k, c, res;
    ll a = (1 << n) - 1;
    int prev;
    // figure out k
    res = q1(0);
    if (res == 1) {
        // &, S = {0}
        k = 1;
    } else {
        // ^, S = {0, c}
        // |, S = {0, c}
        res = q1(a);
        // ^, S = {0, c, \overline{c}}
        // |, S = {0, c, a}

        // check if c == a
        res = q2(0);
        if (res == 2) 


        // if c != a
        res = q2(a);
        if (res == 0) {
            k = 2;
        } else {
            k = 3;
        }
    }


    if (res == 1) {
        k = 2;
        prev = 1;
    } else {
        res = q1(0);
        if (res == 2) {
            prev = 2;
            k = 3;
            cout << "A " << k << " " << a << endl;
            cout.flush();
            return;
        } else {
            res = q2(1);
            if (res == 2) k = 1;
            else k = 3;
            prev = 3;
        }
    }
    ll c = 0LL;
    if (k == 3) {
        // flip one bit at a time
        for (int i = 0; i < n; i++) {
            ll x = (1 << i);
            res = q1(x);
            if (res > prev) {
                c += x;
            }
            prev = res;
        }
    } else if (k == 2) {
        // or all except 1 bit
        for (int i = 0; i < n; i++) {
            ll x = a - (1 << i);
            res = q1(x);
            if (res == prev) {
                c += (1 << i);
            }
            prev = res;
        }
    } else {
        // how to handle and ?
    }
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
