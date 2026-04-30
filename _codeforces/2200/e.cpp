/*
Problem link: https://codeforces.com/contest/2200/problem/E
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
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vi b(all(a));
    sort(all(b));
    bool good = true;
    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) good = false;
    }
    if (good) {
        cout << "Bob" << endl;
        return;
    }
    int m = 0;
    for(int i = 0; i < n; i++) {
        int f = 1;
        for(int j = 2; j <= a[i]; j++) {
            bool g = false;
            while (a[i] % j == 0) {
                g = true;
                a[i] /= j;
            }
            if (f == 1 && g) f = j;
            else if (f != j && g) {
            //     debug(f);
            //     debug(j);
                cout << "Alice" << endl;
                return;
            }
        }
        if (m > f) {
            cout << "Alice" << endl;
            return;
        }
        m = f;
    }
    cout << "Bob" << endl;

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