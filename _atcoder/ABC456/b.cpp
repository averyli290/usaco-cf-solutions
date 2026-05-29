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
    vector<vector<int>> p(3, vector<int >(7, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 6; j++) {
            int x; cin >> x;
            p[i][x]++;
        }
    }

    int tot = 0;

    for(int i = 4; i <= 6; i++) {
        for(int j = 4; j <= 6; j++) {
            for(int k = 4; k <= 6; k++) {
                if (i != j && j != k && i != k) {
                    // cout << i << " " << j << " " << k << endl;
                    // debug(p[0][i]);
                    // debug(p[1][j]);
                    // debug(p[2][k]);
                    tot += p[0][i] * p[1][j] * p[2][k];
                }
            }
        }
    }
    cout << tot / ((long double) 216.0) << endl;
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
