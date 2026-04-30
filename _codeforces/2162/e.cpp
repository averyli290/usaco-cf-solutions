/*
Problem link: https://codeforces.com/contest/2162/problem/E
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
if there are free elements, attempt to use them first to break
if there are no free elements, we know that there are no possibility
for palindromes by setting b[i] = a[i]
*/


void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    set<int> left;
    set<int> free;
    for(int i = 0; i < n; i++) {
        left.insert(i + 1);
        free.insert(i + 1);
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        free.erase(a[i]);
    }

    vi b(k);
    if (sz(free) == 1) {
        int start = *free.begin();
        b[0] = start;
        if (k == 1) {
            cout << b[0] << endl;
            return;
        }
        left.erase(start);
        int next = 1;
        while(next == start || next == a[n - 1]) next = (next % n) + 1;
        left.erase(next);
        b[1] = next;
        int ctr = 2;
        for(int v : left) {
            if (ctr == k) break;
            b[ctr] = v;
            ctr++;
        }
    } else if (sz(free) > 1) {
        int start, next;
        int ctr = 0;
        for (int v : free) {
            if (ctr == 0) start = v;
            else if (ctr == 1) next = v;
            else break;
            ctr++;
        }
        b[0] = start;
        if (k == 1) {
            cout << b[0] << endl;
            return;
        }
        left.erase(start);
        left.erase(next);
        b[1] = next;
        ctr = 2;
        for(int v : left) {
            if (ctr == k) break;
            b[ctr] = v;
            ctr++;
        }
    } else {
        for(int i = 0; i < k; i++) b[i] = a[i];
    }
    for(int i : b) {
        cout << i << " ";
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
