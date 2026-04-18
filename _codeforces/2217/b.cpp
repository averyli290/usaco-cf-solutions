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
    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int p; cin >> p;
    p--;

    int i = 0;
    while(i < p && a[i] == a[p]) i++;

    int b = 0;
    if (i < p) b++;
    int prev = a[i];
    while(i <= p) {
        if (a[i] != prev) b++;
        prev = a[i];
        i++;
    }


    i = n - 1;
    while(i > p && a[i] == a[p]) i--;

    int c = 0;
    if (i > p) c++;
    prev = a[i];
    while(i >= p) {
        if (a[i] != prev) c++;
        prev = a[i];
        i--;
    }


    cout << max(b, c) << endl;
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