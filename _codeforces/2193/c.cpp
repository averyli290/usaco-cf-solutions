/*
Problem link: https://codeforces.com/contest/2193/problem/C
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
the vet said ur fat...
https://www.youtube.com/watch?v=GzTAi3JQ3RM
*/

void solve() {
    int n, q; cin >> n >> q;
    vll a(n), b(n), c(n), pref(n + 1, 0ll);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = n - 1; i >= 0; i--) {
        c[i] = max(b[i], a[i]);
        if (i < n - 1) c[i] = max(c[i + 1], c[i]);
    }
    for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + c[i];
    while(q--) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << " ";
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
