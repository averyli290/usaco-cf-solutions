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
https://www.youtube.com/watch?v=zWoSvb1_vXQ
*/

void solve() {
    int n; cin >> n;

    vi a(n);
    for(int i = 0 ; i < n; i++) cin >> a[i];
    vector<pii> runs;

    int run = 1;
    for(int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            runs.push_back({a[i], run});
            run = 0;
        }
        run++;
    }
    runs.push_back({a[n - 1], run});
    // for(auto [x, y] : runs) {
    //     cout << x << " " << y << endl;
    // }
    int ans = sz(runs);
    int mx = 0;
    for(int i = 0; i < sz(runs) - 1; i++) {
        int v1 = runs[i].second > 1;
        int v2 = runs[i + 1].second > 1;
        // debug(v1);
        // debug(v2);
        if (v1 + v2 == 2) {
            mx = max(mx, 2);
        } else if (v1 + v2 == 1) {
            bool left = true;
            bool right = true;
            if (v1 == 1) { // 1 1 2
                if (i + 2 < sz(runs)) left = (runs[i + 2].first != runs[i].first);
            } else if (v2 == 1) { // 1 2 2
                if (i - 1 >= 0) right = (runs[i - 1].first != runs[i + 1].first);
            }
            if (left && right) mx = max(mx, 1);
        }
    }
    cout << ans + mx << endl;

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
