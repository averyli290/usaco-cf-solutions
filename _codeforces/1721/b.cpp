/*
Problem link: https://codeforces.com/problemset/problem/1721/B
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*
stick to the walls
*/

void solve() {
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    sx--; sy--;

    function<int(int,int)> dist = [&] (int x, int y) { return abs(x - sx) + abs(y - sy); };

    bool good = true;
    for(int i = 0; i < n; i++) {
        if (dist(i, 0) <= d) good = false;
    }
    for(int j = 0; j < m; j++) {
        if (dist(n - 1, j) <= d) good = false;
    }
    if (good) {
        cout << n + m - 2 << endl;
        return;
    }
    good = true;
    for(int j = 0; j < m; j++) {
        if (dist(0, j) <= d) good = false;
    }
    for(int i = 0; i < n; i++) {
        if (dist(i, m - 1) <= d) good = false;
    }
    if (good) {
        cout << n + m - 2 << endl;
        return;
    }
    cout << -1 << endl;
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
