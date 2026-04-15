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
there must be at least as many odds as evens
cannot have no evens and an even amount of odds though
construct by taking a root, get parity of it and update x and y
then, attach y nodes to the root, making y odd subtrees
then, add x nodes to those nodes (1 each) to make x even subtrees
*/

void solve() {
    int x, y; cin >> x >> y;
    if (x > y || (x == 0 && ((y % 2) == 0))) {
        cout << "NO" << endl;
        return;
    }

    int n = x + y;
    vector<pii> ans;
    if (n % 2 == 0) {
        // root node has even
        x--;
    } else {
        // root node has odd
        y--;
    }
    // debug(x);
    // debug(y);
    for(int i = 1; i < y + 1; i++) {
        ans.push_back({1, i + 1});
    }
    for(int i = 1; i < x + 1; i++) {
        ans.push_back({i + 1, i + y + 1});
    }
    cout << "YES" << endl;
    for(auto& [a, b] : ans) {
        cout << a << " " << b << endl;
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
