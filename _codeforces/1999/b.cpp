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
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;

    vi a = {a1, a2};
    vi b = {b1, b2};

    int ans = 0;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            int x1, x2, y1, y2;
            x1 = a[i];
            x2 = a[(i + 1) % 2];
            y1 = b[j];
            y2 = b[(j + 1) % 2];
            int ct = 0;
            if (x1 > y1) ct++;
            if (x1 < y1) ct--;
            if (x2 > y2) ct++;
            if (x2 < y2) ct--;
            if (ct > 0) ans++;
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