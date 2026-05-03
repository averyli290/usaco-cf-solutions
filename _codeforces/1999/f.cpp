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

const long long MOD = 1E9+7;

vll factorial;

ll inv(ll a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}

long long C(ll n, ll k) {
    if (n == 0LL || k == 0LL) return 1LL;
    return factorial[n] * inv(factorial[k] * factorial[n - k] % MOD) % MOD;
}

void solve() {
    ll n, k; cin >> n >> k;
    vi a(n);
    ll numones = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) numones++;
    }
    ll numzeroes = n - numones;
    ll ans = 0LL;
    if (numones < (k + 1) / 2) {
        cout << 0 << endl;
    } else {
        // debug((k + 1) / 2);
        // debug(min(numones, k));
        for(ll i = max((k + 1) / 2, k - numzeroes); i <= min(numones, k); i++) {
            // debug(i);
            // debug(k);
            // debug(numones);
            // debug(C(numones, i));
            // debug(numzeroes);
            // debug(k - i);
            // debug(C(numzeroes, k-i));
            ans += C(numones, i) * C(numzeroes, k - i);
            // debug(ans);
            ans %= MOD;
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial.resize(200005, 0LL);
    factorial[0] = 1LL;
    for (int i = 1; i <= 200005; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}