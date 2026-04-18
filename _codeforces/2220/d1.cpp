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
if 3 of x, then there exists an index where separating on there
will put 2 x's in one part and 1 x in the other: ~10 queries
find index for 1 x using binary search 
separate the other 2 x's using the same process

if query length even, 2 x's in query, retval is even
if query length even, 1 x in query, retval is odd
if query length odd,  2 x's in query, retval is odd
if query length odd,  1 x in query, retval is even

given that [l, r] contains 2 x's if query(l, r) == query(l, r + 1), then a[r + 1] = x
assume that the left half contains 2 x's
binary search [0, r] for when the query value doesn't change between adjacent


given that [l, r] contains 2 x's if query(l, r) == query(l-1, r + 1), then a[l-1] = x
given that [l, r] contains 3 x's if query(l, r) == query(l-1, r), then a[l-1] = x
*/

vi query(int k, vi s) {
    cout << "? " << k;
    for (int v : s) cout << " " v;
    cout << endl;
    cout.flush();

}

void solve() {
    int n; cin >> n;
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