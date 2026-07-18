/*
Problem link:
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
*/

void solve() {
    int h, w; cin >> h >> w;
    int q; cin >> q;
    vector<vector<int>> a(h + 1, vector<int>(w + 1, -1));

    vector<char> x(q);
    for(int i = 0; i < q; i++) {
        int r, c; cin >> r >> c >> x[i];
        r--;
        c--;
        a[r][c] = i;
    }

    for(int i = h - 1; i >= 0; i--) {
        for(int j = w - 1; j >= 0; j--) {
            a[i][j] = max(a[i][j], max(a[i + 1][j], a[i][j + 1]));
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] >= 0) cout << x[a[i][j]];
            else cout << 'A';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
