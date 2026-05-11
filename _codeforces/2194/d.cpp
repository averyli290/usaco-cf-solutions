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
    ll n, m; cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m, 0LL));
    ll ct = 0LL;
    vector<ll> b(n + 1, 0);
    for(ll i = 0; i < n; i++) {
        ll cur = 0;
        for(ll j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) cur++;
        }
        b[i] = cur;
        ct += cur;
    }

    string ans = "";

    ll cur = 0;
    ll j = 0;
    ll i = 0;
    for(; i < n; i++) {
        if (cur + b[i] > ct/2) {
            ll diff = cur + b[i] - ct / 2;
            while (diff > 0) {
                diff -= a[i][j];
                j++;
                ans += 'R';
            }
            if (i < n) {
                i++;
                ans += 'D';
            }
            while(j < m) {
                j++;
                ans += 'R';
            }
            while (i < n) {
                i++;
                ans += 'D';
            }
            cout << (ct / 2) * (ct - ct/2) << endl << ans << endl;
            return;
        }
        cur += b[i];
        ans += 'D';
    }
    while(j < m) {
        j++;
        ans += 'R';
    }
    while(i < n) {
        i++;
        ans += 'D';
    }
    cout << (ct / 2) * (ct - ct/2) << endl << ans << endl;


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
    
    