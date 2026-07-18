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


void solve() {
    int h, w; cin >> h >> w;
    int minh = h + 1;
    int maxh = 0;
    int minw = w + 1;
    int maxw = 0;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                minh = min(minh, i);
                maxh = max(maxh, i);
                minw = min(minw, j);
                maxw = max(maxw, j);
            }
        }
    }
    for(int i = minh; i < maxh + 1; i++) {
        for(int j = minw; j < maxw + 1; j++) {
            cout << a[i][j];
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
