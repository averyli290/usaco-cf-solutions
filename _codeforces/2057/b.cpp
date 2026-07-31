/*
Problem link: https://codeforces.com/contest/2057/problem/B
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
https://www.youtube.com/watch?v=9qN9EF-6IcI
*/

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    vi a(n);
    for(int i = 0;i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pii> b;
    for(auto [k, v] : mp) {
        b.push_back({v, k});
    }
    sort(all(b));
    int ans = sz(b);
    for(int i = 0; i < sz(b); i++) {
        if (k < b[i].first) break;
        k -= b[i].first;
        ans--;
    }
    cout << max(ans,1) << endl;

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
