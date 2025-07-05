/*
Problem link: https://codeforces.com/problemset/problem/1807/F
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
bounds are small, can keep a visited value for every state the ball can be in
*/

map<pii, int> mp = {{{0, 0}, 0}, {{0, 1}, 1}, {{1, 0}, 2}, {{1, 1}, 3}};

void solve() {
    int n, m, i1, j1, i2, j2;
    string dir;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> dir;

    bool vis[n + 1][m + 1][4];
    for (int i = 0; i < n + 1; i++) {
        for(int j = 0; j < m + 1; j++) {
            for (int k = 0; k < 4; k++) {
                vis[i][j][k] = false;
            }
        }
    }
    int i = i1;
    int j = j1;
    pii d;
    if (dir == "DL") d = {0, 0};            // arrange using karnaugh map
    else if (dir == "DR") d = {0, 1};
    else if (dir == "UL") d = {1, 0};
    else if (dir == "UR") d = {1, 1};
    int ans = 0;
    while(true) {
        //cout << i << " " << j << endl;
        //cout << mp[d] << endl;
        if (i == i2 && j == j2) {
            cout << ans << endl;
            return;
        } else if (vis[i][j][mp[d]]) {
            cout << -1 << endl;
            return;
        }
        vis[i][j][mp[d]] = true;
        if (d.first == 0) i++;
        else i--;
        if (d.second == 0) j--;
        else j++;

        bool bounced = false;
        if (i > n) {
            i = n - 1;
            d.first = 1 - d.first;
            ans++;
            bounced = true;
        } else if (i < 1) {
            i = 2;
            d.first = 1 - d.first;
            ans++;
            bounced = true;
        }
        if (j > m) {
            j = m - 1;
            d.second = 1 - d.second;
            if (!bounced) ans++;
        } else if (j < 1) {
            j = 2;
            d.second = 1 - d.second;
            if (!bounced) ans++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
