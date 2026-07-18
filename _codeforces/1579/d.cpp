/*
Problem link: https://codeforces.com/contest/1579/problem/D
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
    set<pii> s;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > 0) s.insert({x, i + 1});
    }
    vector<pii> ans;
    while (sz(s) > 1) {
        auto [f, fidx] = *s.begin();
        auto [b, bidx] = *s.rbegin();
        s.erase(s.begin());
        s.erase(prev(s.end()));
        f--;
        b--;
        if (f > 0) s.insert({f, fidx});
        if (b > 0) s.insert({b, bidx});
        ans.push_back({fidx, bidx});
    }
    cout << sz(ans) << endl;
    for(pii p : ans) cout << p.first << " " << p.second << endl;
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
