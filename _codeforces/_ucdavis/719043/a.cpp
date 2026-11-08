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
    vll a(n);
    vll b(n);
    vll o;
    vll t;
    for(int i = 0;i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0;i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        if (a[i] == 1) o.push_back(b[i]);
        else t.push_back(b[i]);
    }
    sort(all(o));
    sort(all(t));
    ll ans = 0ll;
    if (sz(o) > sz(t)) swap(o, t);
    if (sz(o) == sz(t)) {
        ans -= min(o.front(), t.front());
        for(ll x : o) ans += 2 * x;
        for(ll x : t) ans += 2 * x;
    } else {
        for(int i = 0; i < sz(t) - sz(o); i++) {
            ans -= t[i];
        }
        for(ll x : o) ans += 2 * x;
        for(ll x : t) ans += 2 * x;
    }
    cout << ans << endl;
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
