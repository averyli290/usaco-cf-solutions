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
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int ans = 0;
    multiset<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(a[i]);
    }

    function<bool(int)> check = [&] (int mid) {
        /*
        check mex from greatest to smallest required values instead of bottom up
        because lower values may have more restriction
        */
        multiset<int> s2 = s;
        for(int i = mid - 1; i >= 0; i--) {
            auto ptr = s2.find(i);
            if (ptr != s2.end()) {
                s2.erase(ptr);
            } else {
                // need to find a number at least 2i + 1, take smallest one
                // because larger ones can cover more values in [0, (val - 1) / 2]
                ptr = s2.lower_bound(2 * i + 1);
                if (ptr == s2.end()) return false;
                s2.erase(ptr);
            }
        }
        return true;
    };

    int lo = 0;
    int hi = n + 1;

    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        // debug(lo);
        // debug(hi);
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
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
