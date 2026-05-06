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

int q(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;
    int n2 = n*n;

    // find corner
    int ml = -1;
    int mv = -1;
    for(int i = 1; i <= n2; i++) {
        int res = q(1, i);
        if (res > mv) {
            mv = res;
            ml = i;
        }
    }

    // n^2

    // set at top left
    int corner = ml;
    vector<vi> strips(2*(n-1) + 1, vi{});
    for(int i = 1; i <= n2; i++) {
        strips[q(corner, i)].push_back(i);
    }

    // 2n^2

    vector<vi> ans(2*(n-1)+1);
    int prev_end_label = corner;
    for (int i = 0; i < 2*n-2 + 1; i++) {
        vi strip = strips[i];

        vi ordered_strip(sz(strip));
        int end_label = strip[0];
        if (sz(strip) == 1) {
            ordered_strip = strip;
        } else {

            // get end of strip
            int end_dist = 0;
            for(int j = 1; j < sz(strip); j++) {
                int res = q(strip[0], strip[j]);
                if (res > end_dist) {
                    end_dist = res;
                    end_label = strip[j];
                }
            }
            /*
            1 3 5
            2 4 6
            7 8 9
            */

            // get strip in order
            for(int j = 0; j < sz(strip); j++) {
                ordered_strip[q(end_label, strip[j]) / 2] = strip[j];
            }

            // orient to prev strip
            int res = q(prev_end_label, end_label);
            if (res > 1) reverse(all(ordered_strip));
        }

        ans[i] = ordered_strip;
        prev_end_label = ordered_strip[0];
    }

    cout << "!" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int stripnum = i + j;
            int idx;
            if (stripnum < n) idx = j;
            else idx = j - (stripnum - (n - 1));
            // debug(idx);
            // debug(stripnum);
            cout << ans[stripnum][idx] << " ";
        }
        cout << endl;
        cout.flush();
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
