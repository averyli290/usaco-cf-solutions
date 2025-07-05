/*
Problem link: https://codeforces.com/contest/2065/problem/C2
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

/*
binary search for making value as small as possible while being as big as previous
*/

void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    vi b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(all(b));
    a[0] = min(a[0], b[0] - a[0]);

    for(int i = 1; i < n; i++) {
        // a[i] = b[idx] - a[i]
        // b[idx] - a[i] >= a[i - 1]
        // b[idx] >= a[i] + a[i - 1]
        // cout << "prev: "<< a[i - 1] << " cur: " << a[i] << endl;
        // cout << "looking for: " << a[i - 1] + a[i] << endl;
        // *p >= a[i - 1] + a[i]
        // *p - a[i] >= a[i - 1]
        auto p = lower_bound(all(b), a[i - 1] + a[i]);  
        if (p != b.end()) {
            // if (*p - a[i] >= a[i - 1]) {
            //     a[i] = min(*p - a[i], a[i]);
            // }
            if (a[i] < a[i - 1]) {
                a[i] = *p - a[i];
            } else {
                a[i] = min(*p - a[i], a[i]);
            }
        }
        if (a[i] < a[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout <<endl;
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
