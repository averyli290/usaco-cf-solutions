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
    int n; cin >> n;
    // vector<vector<char>> a(n, vi(n));
    vector<pii> b;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char x; cin >> x;
            if(x == '#') {
                int x1, y1, x2, y2;
                if (i < n / 2) {
                    y1 = n / 2 - i - 1;
                    y2 = n / 2 - i;
                } else {
                    y1 = i - n / 2;
                    y2 = i - n / 2 + 1;
                }
                if (j < n / 2) {
                    x1 = n / 2 - j - 1;
                    x2 = n / 2 - j;
                } else {
                    x1 = j - n / 2;
                    x2 = j - n / 2 + 1;
                }
                b.push_back({x1*x1 + y1*y1, 0});
                b.push_back({x2*x2 + y2*y2, 1});
            }
        }
    }
    sort(all(b));
    int ans = 0;
    int best = 0;
    int cur = 0;
    for(auto [x, y] : b) {
        if (y == 0) {
            cur++;
            if (cur > best) {
                best = cur;
                ans = x;
            }
        } else {
            cur--;
        }
    }
    cout << setprecision(18) << sqrt((double) ans) << endl;
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
