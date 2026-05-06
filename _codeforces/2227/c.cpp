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
    int n; cin >> n;
    vi b;
    vi m2;
    vi m3;
    vi m6;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 6 == 0) {
            m6.push_back(x);
        } else if (x % 3 == 0){
            m3.push_back(x);
        } else if (x % 2 == 0) {
            m2.push_back(x);
        } else {
            b.push_back(x);
        }
    }
    for(int i : m2) cout << i << " ";
    for(int i : b) cout << i << " ";
    for(int i : m3) cout << i << " ";
    for(int i : m6) cout << i << " ";
    cout << endl;

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
