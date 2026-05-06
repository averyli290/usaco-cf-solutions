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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));


    vll ans(n, -1LL);
    int ctr = 1;
    ll prev = 0LL;
    ans[0] = a[n - 1];
    for(int i = 0; i < n - 1; i++) {
        if (a[i] == prev) {
            ans[ctr] = a[i];
            prev++;
            ctr++;
        }
    }

    ll tot = 0LL;
    tot += a[n - 1] * n;

    prev = 0LL;
    for(int i = 0; i < n; i++) {
        // debug(ans[i]);
        // debug(prev);
        while (ans[i] == prev || prev == ans[0]) {
            prev++;
        }
        tot += prev;
    }
    // debug(tot);
    // debug(prev);
    // tot += (prev * (prev - 1LL) / 2LL) + (prev * (n + 1) - (prev));

    cout << tot << endl;
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
