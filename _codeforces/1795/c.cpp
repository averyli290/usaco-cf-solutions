/*
Problem link: https://codeforces.com/problemset/problem/1795/C
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
    vll a(n), b(n), pref(n + 1, 0ll);
    pref.push_back(LLONG_MAX);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        pref[i + 1] = pref[i] + b[i];
    }

    vll change(n + 1, 0ll);
    vll mult(n + 1, 0ll);

    for(int i = 0; i < n; i++) {
        int lo = i + 1;
        int hi = n + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            ll sum = pref[mid] - pref[i];
            if (a[i] >= sum) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        mult[i] += 1;
        mult[hi - 1] -= 1;
        change[hi - 1] -= a[i] - (pref[hi - 1] - pref[i]);
    }

    ll cur = 0ll;
    for(int i = 0; i < n; i++) {
        // debug(mult[i]);
        cur += mult[i];
        cout << cur * b[i] - change[i] << " ";
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
