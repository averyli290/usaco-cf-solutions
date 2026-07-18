/*
Problem link: https://codeforces.com/contest/2039/problem/C2
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
x ^ y

*/

vector<ll> f(ll x) {
    vll ret;
    for(int d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            ret.push_back(d);
            if (d * d != x) ret.push_back(x / d);
        }
    }
    return ret;
}

void solve() {
    ll x, m; cin >> x >> m;

    ll ystart = 1ll;
    while(ystart <= x) {
        ystart <<= 1;
    }
    ll yend = ystart - 1;
    ystart >>= 1;

    ll ans = 0ll;
    for(int y = ystart; y <= min(m, yend); y++) {
        ll div = x ^ y;
        if (y == x) continue;
        if (y % div == 0 || x % div == 0) ans++;
    }
    cout << ans << endl;



    // set<ll> ans;
    // vll fac = f(x);
    // for(int i = 0; i < sz(fac); i++) {
    //     ll div = fac[i];
    //     ll y = div ^ x;
    //     if(y <= m && y > 0) ans.insert(y);
    // }
    // cout << sz(ans) << endl;
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
