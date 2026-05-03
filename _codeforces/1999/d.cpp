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
    string s1, s2; cin >> s1 >> s2;
    int i = 0;
    int j = 0;
    int n = s1.length();
    int m = s2.length();
    string ans = "";
    while(i < n && j < m) {
        if (s1[i] == s2[j]) {
            ans += s1[i];
            i++;
            j++;
        } else if (s1[i] == '?') {
            ans += s2[j];
            i++;
            j++;
        } else {
            ans += s1[i];
            i++;
        }
    }
    if (j < m) cout << "NO" << endl;
    else {
        while(i < n) {
            if (s1[i] == '?') ans += 'a';
            else ans += s1[i];
            i++;
        }
        cout << "YES" << endl;
        cout << ans << endl;
    }
    
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