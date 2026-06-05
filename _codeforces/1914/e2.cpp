/*
Problem link: https://codeforces.com/contest/1914/problem/E2
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
    ll ans = 0ll;
    vll a(n);
    vll b(n);
    vector<bool> used(n, false);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<ll, int>> c(n);
    for(int i = 0; i < n; i++) c[i] = {(b[i] - 1ll) + (a[i] - 1ll), i};
    sort(all(c));
    reverse(all(c));
    ll A = 0ll;
    ll B = 0ll;
    for(int i = 0; i < n; i++) {
        if (i % 2 == 0) A += a[c[i].second] - 1;
        else B += b[c[i].second] - 1;
    }
    cout << A - B << endl;

    // priority_queue<pair<ll, int>> pq1;
    // priority_queue<pair<ll, int>> pq2;
    // for(int i = 0; i < n; i++) {
    //     pq1.push({(b[i] - 1ll) + (a[i] - 1ll), i});
    //     pq2.push({(a[i] - 1ll) + (b[i] - 1ll), i});
    // }
    // ll A = 0ll;
    // ll B = 0ll;
    // for(int i = 0; i < n; i++) {
    //     bool done = false;
    //     if (i % 2 == 0) {
    //         while (!done) {
    //             auto [val, idx] = pq1.top();
    //             pq1.pop();
    //             if (!used[idx]) {
    //                 // debug(idx);
    //                 done = true;
    //                 A += a[idx] - 1;
    //                 used[idx] = true;
    //             }
    //         }
    //     } else {
    //         while (!done) {
    //             auto [val, idx] = pq2.top();
    //             pq2.pop();
    //             if (!used[idx]) {
    //                 debug(idx);
    //                 done = true;
    //                 B += b[idx] - 1;
    //                 used[idx] = true;
    //             }
    //         }
    //     }
    // }
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
