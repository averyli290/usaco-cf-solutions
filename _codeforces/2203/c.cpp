/*
Problem link:
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;


void solve() {
    ll s, m; cin >> s >> m;
    if (__builtin_ctz(m) > __builtin_ctz(s)) {
        cout << -1 << endl;
        return;
    }

    vll ans(64, 0LL);
    for (int i = 0; i < 64; i++) {
        if(((s >> i) & 0b1) == 0b1) {
            ll cur = 1;
            int j = i;
            while (((m >> j) & 0b1) != 0b1) {
                cur *= 2;
                j--;
            }
            ans[j] += cur;
        }
    }
    // for(int i = 0; i < 64; i++) {
    //     cout << ans[i];
    // }
    // cout << endl;

    function<bool(ll)> check = [&](ll t) {
        vll a = ans;
        for(int i = 63; i > 0; i--) {
            if (a[i] > 0LL && ((m >> i) & 0b1) == 0b0) {
                a[i - 1] += 2 * a[i];
                a[i] = 0LL;
            }
            if (a[i] > t) {
                a[i - 1] += (a[i] - t) * 2;
                a[i] = t;
            }
        }
        // for(int i = 0; i < 64; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        for(int i = 0; i < 64; i++) {
            if (a[i] > t || a[i] < 0) return false;
        }
        return true;
    };

    ll lo = 0;
    ll hi = s;
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        // debug(check(mid));
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;

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
