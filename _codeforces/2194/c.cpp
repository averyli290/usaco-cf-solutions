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


vi factors(int x) {
    vi res;
    for(int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i * i == x) res.push_back(i);
            else {
                res.push_back(i);
                res.push_back(x / i);
            }
        }
    }
    sort(all(res));
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<string> a(k);
    vector<vector<bool>> fmaps(n, vector<bool>(26, false));

    function<int(char)> conv = [&](char c) {
        return c - 'a';
    };

    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            fmaps[i][conv(a[j][i])] = true;
        }
    }

    vi fa = factors(n);
    string alpha ="abcdefghijklmnopqrstuvwxyz"; 
    for(int f : fa) {
        int jump = n / f;
        string ans = "";
        bool done = true;
        for(int i = 0; i < f; i++) {
            vi freq(26, 0);
            for(int j = i; j < n; j += f) {
                // debug(j);
                for(char c : alpha) freq[conv(c)] += fmaps[j][conv(c)];
            }
            bool good = false;
            for (char c : alpha) {
                if (freq[conv(c)] >= n / f) {
                    good = true;
                    ans += c;
                    break;
                }
            }
            if (!good) {
                done = false;
                break;
            }
        }
        if (done) {
            int temp = n / f;
            while (temp--) cout << ans;
            cout << endl;
            return;
        }
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