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

/*
count switches
each flip can handle 2 switches at most
if one region has too many switches, have to do them all manually

b[i] = # of elts s.t. a[i] % x == 0

left = 0
right = 0
while (b[right] < k) right++;
// b[right] = k;
[b[left], b[right]] there are k elts which are divisible by x

new_left = left;
set<int> left_set;
while (b[left] == b[new_left]) {
    left_set.insert(b[new_left]);
    new_left++;
}

new_right = right;
cur_ans = 0;
while (b[new_right] < b[left] + k + 1) {
    new_right++;
    num_less = (int) (left_set.upper_bound(b[new_right]) - 1 - s.begin());
    cur_ans += num_less;
}
[b[left], b[new_right]] there are k+1 elts which are divisible by x
ans += (new_left - left) * (new_right - right)
left = new_left; right = new_right;

*/

void solve() {
    int n, k; cin >> n >> k;
    vi a(n), p(k);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> p[i];

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
