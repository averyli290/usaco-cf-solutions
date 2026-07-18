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


void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 1;
    int r = n;
    vll o(n + 1,0ll);
    vll e(n + 1,0ll);
    for(int i = 0; i < n; i++) {
        o[i + 1] = o[i];
        e[i + 1] = e[i];
        if (i % 2 == 0) o[i + 1] += a[i];
        else e[i + 1] += a[i];
    }

    function<bool(int, int)> check = [&] (int l, int r) {
        ll odds = o[r] - o[l - 1];
        ll evens = e[r] - e[l - 1];
        return odds == evens;
    ;}

    while(l <= r) {
        debug(l);
        debug(r);
        if (check(l, r)) {
            cout << "YES" << endl;
            return;
        } else if (odds < evens) {
            if (l % 2 == 1) {
                if (r % 2 == 1) {
                    l += 2;
                    r -= 2;
                } else {
                    r--;
                }
            } else {
                cout <<"NO" << endl;
            }
        } else {
            if (l % 2 == 1) {
                if (r % 2 == 1) {
                    l += 2;
                    r -= 2;
                } else {
                    r--;
                }
            } else {
                cout <<"NO" << endl;
            }
        }
    }
    cout << "NO" << endl;
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
