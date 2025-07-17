/*
Problem link: https://codeforces.com/contest/2004/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;

/*
......
..x...
..x...
...x..
......

......
.x....
.x....
..x...
......

......
..x...
...x..
...x..
......

......
....x.
...b..
..b...
...b..

tile such that exactly one . is covered and all b are covered

1, 3, 5, 

op adds 4, adds 3 and deletes 1, deletes 4, deletes 2 and adds 2, deletes 3 and adds 1
+4, +2, -4, +0, -2

odd # of lightbulbs

# of lightbulbs in a column doesn't change parity, can get x coord 

in a x coordinate, how to find y?

op doesn't change parity of target row, changes parity of above and below

op doesn't change parity of diagonals, can determine answer from diag and col

*/


void solve() {
    int n; cin >> n;
    map<int, vi> m1;
    map<int, int> m2;
    vector<pii> a;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        m1[x].push_back(y);
        m2[x+y]++;
    }

    int ansx, ansy;
    for(auto& [k, v] : m1) {
        if (sz(v) % 2 == 1) {
            ansx = k;
            break;
        }
    }
    for(auto& [k, v] : m2) {
        if (v % 2 == 1) {
            ansy = k - ansx;
            break;
        }
    }
    cout << ansx << " " << ansy << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
