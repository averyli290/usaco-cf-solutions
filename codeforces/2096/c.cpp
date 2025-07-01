/*
Problem link: https://codeforces.com/contest/2096/problem/C
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

vi add(vi v) {
    vi ret = v;
    for (int i = 0; i < sz(ret); i++) ret[i]++;
    return ret;
}

bool check(vi &v1, vi &v2) {
    for (int i = 0; i < sz(v1); i++) {
        if (v1[i] == v2[i]) return false;
    }
    return true;
}

const ll LARGE_NUM = 1E14;

void solve() {
    int n; cin >> n;
    vector<vi> grid(n, vi(n, 0));
    vector<vi> grid_rot(n, vi(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            grid_rot[i][j] = grid[j][i];
        }
    }
    vll a(n);
    vll b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // fixing vertical (adding to rows)
    vector<vll> dpv(n, vll{LARGE_NUM, LARGE_NUM});
    dpv[0][0] = 0; dpv[0][1] = a[0];
    vi prev_added = add(grid[0]);
    for(int i = 1; i < n; i++) {
        vi cur_added = add(grid[i]);
        if (check(grid[i - 1], grid[i])) dpv[i][0] = min(dpv[i][0], dpv[i - 1][0]);
        if (check(prev_added, grid[i])) dpv[i][0] = min(dpv[i][0], dpv[i - 1][1]);
        if (check(grid[i - 1], cur_added)) dpv[i][1] = min(dpv[i][1], dpv[i - 1][0] + a[i]);
        if (check(prev_added, cur_added)) dpv[i][1] = min(dpv[i][1], dpv[i - 1][1] + a[i]);
        prev_added = cur_added;
    }

    // fixing horizontal (adding to cols)
    vector<vll> dph(n, vll{LARGE_NUM, LARGE_NUM});
    dph[0][0] = 0; dph[0][1] = b[0];
    prev_added = add(grid_rot[0]);
    for(int i = 1; i < n; i++) {
        vi cur_added = add(grid_rot[i]);
        if (check(grid_rot[i - 1], grid_rot[i])) dph[i][0] = min(dph[i][0], dph[i - 1][0]);
        if (check(prev_added, grid_rot[i])) dph[i][0] = min(dph[i][0], dph[i - 1][1]);
        if (check(grid_rot[i - 1], cur_added)) dph[i][1] = min(dph[i][1], dph[i - 1][0] + b[i]);
        if (check(prev_added, cur_added)) dph[i][1] = min(dph[i][1], dph[i - 1][1] + b[i]);
        prev_added = cur_added;
    }
    // cout << "b sum: " << min(dph[n - 1][0], dph[n - 1][1]) << endl;
    // cout << "a sum: " << min(dpv[n - 1][0], dpv[n - 1][1]) << endl;
    if ((dph[n - 1][0] == LARGE_NUM && dph[n - 1][1] == LARGE_NUM) || 
        (dpv[n - 1][0] == LARGE_NUM && dpv[n - 1][1] == LARGE_NUM)) {
            cout << -1 << endl;
            return;
    }
    cout << min(dph[n - 1][0], dph[n - 1][1]) + min(dpv[n - 1][0], dpv[n - 1][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
