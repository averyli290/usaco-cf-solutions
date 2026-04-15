/*
Problem link: https://codeforces.com/contest/2210/problem/B
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
go backwards, you either sit on current chair (skipping the one before) or skip current chair
if already corresponds to a future one

simpler to just choose to only sit on chairs which exclude chairs behind them,
it should work to do this because choosing this set is always possible
and choosing any other chair which excludes chair in front will always remove
at least 1 other chair which could have been sat on, which will never increase the total score
due to the sequence being a permutation.
*/

void solve() {
    int n; cin >> n;
    vi p1(n + 1);
    vi p2(n + 1);
    // set<int> used;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x <= i) ans++;
    }
    // for(int i = 0; i < n; i++) {
    //     int x; cin >> x;
    //     p1[i + 1] = x;
    //     p2[x] = i + 1;
    // }

    // int cur = 0;
    // int ans = 0;
    // stack<int> s;
    // for(int i = n; i > 0; i--) {
    //     if (used.find(i) == used.end()) {
    //         if (p1[i] > i) {
    //             while(size(s) > 0 && s.top() >= p1[i]) {
    //                 int remove = s.top();
    //                 s.pop();
    //                 cur--;
    //                 used.erase(p2[remove]);
    //                 // used.clear();
    //             }
    //         }
    //         s.push(i);
    //         debug(i);
    //         debug(p2[i]);
    //         used.insert(i);
    //         used.insert(p2[i]);
    //         cur++;
    //     }
    //     debug(cur);
    //     ans = max(cur, ans);
    // }
    cout << ans << endl;
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
