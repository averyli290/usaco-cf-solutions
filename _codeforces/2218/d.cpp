/*
Problem link: https://codeforces.com/contest/2218/problem/C
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

vll primes;

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << primes[i] * primes[i + 1] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> is_prime(150000, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 150000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 150000; j += i)
                is_prime[j] = false;
        }
    }
    for(ll i = 1; i < 150000; i++) if (is_prime[i]) primes.push_back(i);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
