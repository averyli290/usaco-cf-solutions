/*
Problem link: https://codeforces.com/problemset/problem/976/C
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
    vi a(n), b(n);
    vector<pii> c(n);
    set<int> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        s.insert(b[i]);
        c[i] = {a[i], -b[i]};
    }
    sort(all(c));
    for(int i = 0; i < n; i++) {
        int cur = -c[i].second;
        auto ptr = upper_bound(all(c), cur);
        if (ptr != c.begin()) {
            ptr--;
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
