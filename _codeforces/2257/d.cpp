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
    ll S; int q; cin >> S >> q;

    vll div;
    for(ll d = 1ll; d * d <= S; d++) {
        if (S % d == 0) {
            div.push_back(d);
            if (d != S / d) div.push_back(S / d);
        }
    }
    sort(all(div));
    int n = sz(div);
    vll pref(n + 1, 0ll);
    ll tot = 0ll;
    ll prev = 0ll;
    for(int i = 0; i < n; i++) {
        debug(div[i]);
        tot += S - (prev * div[i]);
        pref[i + 1] = pref[i] + div[i];
        prev = div[i];
    }
    debug(tot);
    return;
    while (q--) {
        ll x, y; cin >> x >> y;
        ll cur = tot;
        // find y value which > our y
        auto ptr = upper_bound(all(div), y);
        if (ptr != div.end()) {
            ll lastx = S / *ptr;
            int diff = ptr - div.begin();
            cur -= (pref[n] - pref[diff]) - lastx * y;
        }

        // find x value > our x
        ptr = upper_bound(all(div), x);
        if (ptr != div.end()) {
            ll lasty = S / *ptr;
            int diff = ptr - div.begin();
            cur -= (pref[n] - pref[diff]) - lasty * x;
        }
        cout << cur << endl;
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
