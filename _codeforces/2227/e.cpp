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
lowest 
*/

void solve() {
    int n; cin >> n;
    vll a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vll b(n);
    ll cur = a[n - 1];
    ll ans = 0LL;
    for(int i = n - 1; i >= 0; i--) {
        cur = min(a[i], cur);
        b[i] = cur;
        ans += a[i] - cur;
    }

    int i = n - 1;
    ll streak = 1LL;
    ll add = 0LL;
    while (i > 0) {
        if (b[i] > b[i - 1]) {
            add = max(add, streak - 1);
            streak = 1;
        }
        else streak++;
        i--;
    }
    add = max(add, streak - 1LL);
    streak = 1;
    cout << add + ans << endl;
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
