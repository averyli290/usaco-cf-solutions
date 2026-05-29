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
can always make a free value smaller if needed, but if there is a set value then
the last free value index is reset to -1
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vll a(n);
    vll c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    ll cmax = c[0];
    for(int i = 1; i < n; i++) {
        if (c[i] < cmax) {
            cout << "NO" << endl;
            return;
        }
        cmax = max(c[i], cmax);
    }
    vll b(n, 0LL);

    ll prefsum = 0LL;
    ll sum = 0LL;
    int lidx = -1;
    for(int i = 0; i < n; i++) {
        // debug(i);
        if (s[i] == '1') {
            b[i] = a[i];
            prefsum += b[i];
            sum = max(sum, prefsum);
            if (sum < c[i]) {
                cout << "NO" << endl;
                return;
            }
            if (sum > c[i]) {
                if (lidx == -1) {
                    cout << "NO" << endl;
                    return;
                }
                b[lidx] -= sum - c[i];
                lidx = -1;
            sum = max(sum, prefsum);
            }
        } else {
            prefsum += b[i];
            sum = max(sum, prefsum);
            if (sum > c[i]) {
                if (lidx == -1) {
                    cout << "NO" << endl;
                    return;
                }
                b[lidx] -= sum - c[i];
                lidx = i;
            } else if (sum < c[i]) {
                if (lidx == -1) {
                    cout << "NO" << endl;
                    return;
                }
                b[lidx] -= sum - c[i];
                lidx = -1;
            }
        }
    }
    cout << "YES" << endl;
    for(ll v : b) {
        cout << v << " ";
    }
    cout << endl;
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
