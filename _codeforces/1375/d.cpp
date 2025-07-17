/*
Problem link: https://codeforces.com/contest/1375/problem/D
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
want to construct 0, 1, ..., n - 1

placing mex value at its corresponding index works?
will always get a value in the correct position

note: MEX will always give a point which is not in the correct position, or n
if a point is in the correct position, it cannot have the mex set correctly

keep track of what is in bad position, reroll by setting a bad position to n
if mex ends up as N.

*/


int mex(vi &a) {
    set<int> b = set<int>{a.begin(), a.end()};
    int n  = sz(b);
    for (int i = 0; i < n + 1; i++) {
        if (b.find(i) == b.end()) {
            return i;
        }
    }
}


void solve() {
    int n; cin >> n;
    vi a(n);
    vi ans;
    set<int> baddies;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != i) {
            baddies.insert(i);
        }
    }

    while (sz(baddies) > 0) {
        int curmex = mex(a);
        auto ptr = baddies.find(curmex);
        if (ptr != baddies.end()) {
            baddies.erase(ptr);
            a[curmex] = curmex;
            ans.push_back(curmex);
        } else {
            int idx = *(baddies.begin());
            // cout << "curmex here: " << curmex << endl;
            a[idx] = curmex;
            ans.push_back(idx);
        }
    }
    // for(int v : a) {
    //     cout << v << " ";
    // }
    // cout << endl;
    cout << sz(ans) << endl;
    for(int v : ans) {
        cout << v + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
