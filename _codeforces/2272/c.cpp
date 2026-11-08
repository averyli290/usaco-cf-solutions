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
0 6 8 10 13 14 16 19 25 31

0 3 6 8 10 13 14 16 19 22 25 28 31
*/


void solve() {
    int n; int x; cin >> n >> x;
    vll a(n);
    for(int i = 0 ; i <n ; i++) {
        cin >> a[i];
    }

    ll lo = 1;
    ll hi = a.back() - a.front();
    while(lo < hi) {
        ll mi = (lo + hi) / 2;
        int ct = 0;
        vll b;
        // debug(mi);
        for(int i = 0 ; i < n - 1; i++) {
            if (a[i] + mi < a[i + 1]) {
                if (i == 0) {
                    b.push_back(a[i]);
                } else {
                    b.push_back(a[i + 1]);
                }
            }
        }
        // if (a[n - 1] - a[n - 2] > mi) b.push_back(a[n-1]);
        vector<bool> c(sz(b), false);
        for(int i = 0; i < sz(b) - 1; i++) {
            if (!c[i]) {
                if (b[i] + 2 * mi >= b[i + 1]) {
                    c[i] = true;
                    c[i + 1] = true;
                    ct++;
                }
            }
        }
        // for(auto v : b) cout << v << " ";
        // cout << endl;
        for(bool v : c) if (!v) ct++;
        // debug(ct);
        if (ct <= x) {
            hi = mi;
        } else {
            lo = mi + 1;
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
