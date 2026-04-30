/*
Problem link: https://codeforces.com/contest/2218/problem/G
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

const long long MOD = 676767677;


void solve() {
    int n, m; cin >> n >> m;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vll b(m, 0LL);
    for(int i = 0; i < n; i++) {
        bool bad = true;
        if (a[i] != 0){
            if (i > 0 && a[i - 1] < a[i]) bad = false;
            if (i < n - 1 && a[i + 1] < a[i]) bad = false; 
            if (bad) {
                cout << 0 << endl;
                return;
            }
        } 
        b[a[i]]++;
    }
    vll pref(m + 1, 0LL);
    for(int i = 0; i < m; i++) pref[i + 1] = pref[i] + b[i];

    ll ans = 1LL;
    for(int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        
        ll mintime = LLONG_MAX;
        if (i > 0) {
            mintime = min(mintime, a[i - 1]);
        } 
        if (i < n - 1) {
            mintime = min(mintime, a[i + 1]);
        }

        // neighbors sit down right before you,
        // [1, tot number of sitting people before current time] works
        if (a[i] - mintime == 1LL) {
            ans = (ans * pref[a[i]]) % MOD;
        }
        // neighbors have sat down long (at least 2 time) before you, need to wait for at least
        // (tot number of sitting people before current time - 1) + 1 people to sit first, 
        // [(tot number of sitting people before current time - 1) + 1, tot number of sitting people before current time] people works
        else {
            ans = (ans * (pref[a[i]] - pref[a[i] - 1])) % MOD;
        }
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
