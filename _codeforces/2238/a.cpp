/*
Problem link: https://codeforces.com/contest/2238/problem/A
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
    int n, c; cin >> n >> c;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    bool good = true;
    for(int i = 0; i < n; i++) {
        if (a[i] >= b[i])  ans += a[i] - b[i];
        else {
            good = false;
            break;
        }
    }
    if (good) {
        cout << ans << endl;
        return;
    }

    good = true;
    sort(all(a));
    sort(all(b));
    ans = c;
    for(int i = 0; i < n; i++) {
        if (a[i] >= b[i])  ans += a[i] - b[i];
        else {
            good = false;
            break;
        }
    }
    if (good) {
        cout << ans << endl;
        return;
    }
    cout << -1 << endl;
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
