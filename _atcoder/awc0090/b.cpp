/*
Problem link: https://atcoder.jp/contests/awc0090/tasks/awc0090_b
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
    int l, n, c; cin >> l >> n >> c;
    vi p(n), w(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i] >> w[i];
    }
    int a = 0;
    int b = c;
    for(int i = 0; i < n; i++) {
        if (p[i] - a > b) {
            cout << "-1" << endl;
            return;
        }
        b -= p[i] - a;
        b = min(c, b + w[i]);
        a = p[i];
    }
    if (l - a > b) {
        cout << "-1" << endl;
        return;
    }
    cout << b - (l - a) << endl;

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
