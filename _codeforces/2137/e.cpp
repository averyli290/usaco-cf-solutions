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
const long long INF = 1e18;


void solve() {
    // KISS
    ll n, k; cin >> n >> k;
    vll a(n);
    map<ll, ll> m;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    sort(all(a));
    ll mex = 1;
    for(ll i = 0; i < n; i++) {
        if (a[i] == mex) mex += 1;
        else if (a[i] > mex) break;
    }
    // mex 1
    ll maxval = mex;
    for(auto [key, v] : m) {
        if (key > mex) {
            m[mex] += v;
            m[key] -= v;
        } else { // key < mex
            if (m[key] >= 2) {
                maxval = min(key, maxval);
                m[mex] += v;
                m[key] -= v;
            }
        }
    }

    // mex 2
    ll ans = 0;
    bool woah = false;
    map<ll, ll> m2;
    for(auto [key, v] : m) {
        ans += key * v;
        if (key > maxval) {
            m2[maxval] += v;
        } else if (key < maxval) {
            m2[key] = v;
        }
        else if (key == maxval && v >= 2) {
            woah = true;
            m2[maxval + 1] = v;
        } else {
            m2[maxval] = v;
        } 
    }

    if (k == 1) {
        cout << ans << endl;
        return;
    }

    ans = 0;
    for(auto [key, v] : m2) {
        ans += key * v;
    }
    // cout << "m2: " << endl;
    // for(auto [key, v] : m) {
    //     cout << key << " " << v << endl;
    // }
    // cout << "maxval " << maxval << endl;
    if (k % 2 == 0) {
    } else {
        if (m2[maxval + 1] == 0 && woah) ans += m2[maxval];
        else if (woah) ans -= m2[maxval + 1];
        //ans += m[maxval + 1] * (maxval);
    }
    cout << ans << endl;
    /*
    
    6 6 2 4 3 0 1 8
    0 1 2 3 4 6 6 8: 0
    0 1 2 3 4 5 5 5: 1
    0 1 2 3 4 6 6 6: 2
    0 1 2 3 4 5 5 5: 3
    0 1 2 3 4 6 6 6: 4
    0 1 2 3 4 5 5 5: 5
    0 1 2 3 4 6 6 6: 6
    0 1 2 3 4 5 5 5: 7

    0 0: 0
    1 1: 1
    0 0: 2

    0 2: 0
    1 0: 1
    0 1: 2
    1 0: 3
    */

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
