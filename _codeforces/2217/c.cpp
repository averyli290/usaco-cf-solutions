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
x x x x x
x x x x x
x x x x x
x x x x x
x x x x x

*/
ll inv(ll a, ll mod) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a, mod) % mod;
}

void solve() {
    ll n, m, a, b; cin >> n >> m >> a >> b;
    if (a == 1 && b == 1) {
        cout << "YES" << endl;
        return;
    }
    if (gcd(a, n) > 1 && gcd(b, m) > 1) {
        cout << "NO" << endl;
        return;
    }

    ll c = inv(a, n);
    ll d = inv(b, m);
    ll l = lcm(c, d);
    ll g = gcd(c, d);
    
    if ()

    cout << "YES" << endl;
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