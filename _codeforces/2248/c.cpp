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
1,4,9,16
*/

void solve() {
    int n; cin >> n;
    vi b(2*n);
    vector<vll> a(n, vll(2,-1));
    for(int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        x--;
        b[i] = x;
        if (a[x][0] == -1) a[x][0] = i;
        else a[x][1] = i;
    }
    vll dp(2*n + 1, 0ll);
    for(ll i = 0; i < 2*n; i++) {
        dp[i + 1] = max(dp[i] + 1, dp[a[b[i]][0]] + (i - a[b[i]][0] + 1) * (i - a[b[i]][0] + 1));
    }
    cout << dp[2 * n] << endl;
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