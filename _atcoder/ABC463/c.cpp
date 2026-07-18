/*
Problem link:
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
    int n;cin >>n;
    vi h(n);
    vi l(n);
    vector<pii> a(n);
    
    multiset<int> hs;
    for(int i = 0; i < n; i++) {
        cin >> h[i] >> l[i];
        hs.insert(h[i]);
        a[i] = {l[i], h[i]};
    }
    sort(all(a));
    sort(all(l));
    vi suff(n);
    for(int i = 0; i < n; i++) {
        suff[i] = *hs.rbegin();
        hs.erase(hs.find(a[i].second));
    }

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        int idx = lower_bound(all(l), t + 1) - l.begin();
        cout << suff[idx] << endl;
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
