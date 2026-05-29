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

const long long MOD = 998244353;

void solve() {
    string s; cin >> s;
    int n = s.length();
    char prev = 'd';
    ll ans = 0LL;
    ll previdx = 0;
    for(int i = 0; i < n; i++) {
        if (prev == s[i]) {
            ll len = i - previdx;
            ans += (len * (len + 1) / 2);
            ans %= MOD;
            previdx = (long long) i;
        }
        prev = s[i];
    }
    ll len = n - previdx;
    ans += (len * (len + 1) / 2);
    ans %= MOD;
    cout << ans << endl;

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
