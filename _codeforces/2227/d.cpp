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
    // three cases
    vi a(2 * n);
    vector<vi> b(n);
    int c = -1;
    int d = -1;
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }

    int s1 = b[0][0];
    int s2 = b[0][1];

    int ans = 0;
    set<int> s;
    // s1
    int curans = 0;
    int length = 0;
    s.clear();
    while (s1 - length >= 0 && s1 + length < 2 * n) {
        if (a[s1 - length] != a[s1 + length]) break;
        s.insert(a[s1 -length]);
        length++;
    } 
    curans = 0;
    while (s.find(curans) != s.end()) curans++;
    ans = max(curans, ans);

    // s2
    length = 0;
    s.clear();
    while (s2 - length >= 0 && s2 + length < 2 * n) {
        if (a[s2 - length] != a[s2 + length]) break;
        s.insert(a[s2 -length]);
        length++;
    } 
    curans = 0;
    while (s.find(curans) != s.end()) curans++;
    ans = max(curans, ans);

    // s1 and s2
    int diff = abs(s2 - s1);
    if (diff % 2 == 0) {
        // has middle
        int mp = (s2 + s1) / 2;
        length = 0;
        s.clear();
        while (mp - length >= 0 && mp + length < 2 * n) {
            if (a[mp - length] != a[mp + length]) break;
            s.insert(a[mp-length]);
            length++;
        } 
        curans = 0;
        while (s.find(curans) != s.end()) curans++;
        ans = max(curans, ans);
    } else {
        int mp = (s2 + s1) / 2;
        length = 0;
        s.clear();
        while (mp - length >= 0 && mp + length + 1 < 2 * n) {
            if (a[mp - length] != a[mp + length + 1]) break;
            s.insert(a[mp-length]);
            length++;
        } 
        curans = 0;
        while (s.find(curans) != s.end()) curans++;
        ans = max(curans, ans);
    }
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
