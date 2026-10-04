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
    int n, k; cin >> n >> k;
    if (k < n || k >= 2*n) {
        cout << -1 << endl;
        return;
    }
    vector<vi> ans(n, vi(n, 0));
    int cur = 1;
    int ci = 0;
    int diag = 2 * n - k;
    for(int i = 0; i < n; i++) {
        if (diag > 0) {
            ans[ci][i] = cur;
            diag--;
        } else {
            ci--;
            ans[ci][i] = cur;
        }
        ci++;
        cur++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (ans[i][j] == 0) {
                cout << cur << " ";
                cur++;
            } else {
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
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
