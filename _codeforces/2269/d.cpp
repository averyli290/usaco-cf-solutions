/*
Problem link: https://codeforces.com/contest/2269/problem/D
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
*/

bool f(int x) {
    return ((x == 5) || (x == 10));
}


void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == n - 1) {
            if (a[n - 1] % 3 == 0 && !f(a[n - 2])) ans++;
        } else {
            if (a[i] % 3 == 0 || f(a[i])) ans++;
        }

    }
    cout << ans << " ";
    while(q--) {
        int p, x; cin >> p >> x;
        p--;
        if (p == n - 1) {
            if (a[n - 1] % 3 == 0) {
                if (f(a[n - 2])) {
                    // do nothing
                } else {
                    ans--;
                }
            }
            a[n - 1] = x;
            if (a[n - 1] % 3 == 0 && !f(a[n - 2])) ans++;
        } else {
            if (f(a[p])) ans--;
            a[p] = x;
            if (f(a[p])) ans++;
        }
        cout << ans << " ";
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
