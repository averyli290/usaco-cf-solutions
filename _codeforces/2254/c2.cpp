/*
Problem link: https://codeforces.com/contest/2254/problem/C2
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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    array<int, 2> cta = {0, 0};
    array<int, 2> ctb = {0, 0};
    vector<vi> as(2, vi{});
    vector<vi> bs(2, vi{});
    for(int i = 0 ;i < n; i++) {
        if (a[i] == '1') {
            cta[i % 2]++;
            as[i % 2].push_back(i);
        }
        if (b[i] == '1') {
            ctb[i % 2]++;
            bs[i % 2].push_back(i);
        }
    }
    if (cta[0] != ctb[0] || cta[1] != ctb[1]) {
        cout << -1 << endl;
        return;
    }
    ll ans = 0ll;
    for(int j = 0 ; j < cta[0]; j++) {
        ans += abs(as[0][j] - bs[0][j]);
    }
    for(int j = 0 ; j < cta[1]; j++) {
        ans += abs(as[1][j] - bs[1][j]);
    }
    cout << ans / 2 << endl;
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
