/*
Problem link: https://codeforces.com/contest/2244/problem/G
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

i got bored https://www.youtube.com/watch?v=0j7yR4Dze2o

*/


void update(vll& st, int ind, int val, int at, int atl, int atr) {       // st[at] describes [atl, atr] inclusive
    if (atl == atr) {
        st[at] = val;
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update(st, ind, val, 2 * at, atl, mid);
    else update(st, ind, val, 2 * at + 1, mid + 1, atr);
    st[at] = max(st[2*at], st[2*at+1]);
}


ll query(vll& st, int s, int e, int at, int atl, int atr) {         // query [s, e] (0-indexed)
    if (atr < s || e < atl) return 0ll;
    if (s <= atl && atr <= e) return st[at];
    int mid = (atl + atr) / 2;
    ll left = query(st, s, e, 2 * at, atl, mid);
    ll right = query(st, s, e, 2 * at + 1, mid + 1, atr);
    return max(left, right);
}


void solve() {
    int n; cin >> n;
    vll a(n);
    vll st(n << 2, 0ll);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0ll;
    vector<vector<pll>> updates(n, vector<pll>{});
    for(int i = 0; i < n; i++) {
        for(auto [updidx, updval] : updates[i]) {       // process pending updates
            update(st, updidx, updval, 1, 0, n - 1);
        }
        ll val = a[i];
        ans = max(ans, val);
        int left = i - (val + 1);
        int right = i + (val + 1);
        ll q = query(st, 0, left, 1, 0, n - 1);
        ans = max(ans, val + q);
        if (right < n) updates[right].push_back(pll{i, val + q});     // store to be updated later
    }
    cout << ans << endl;

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
