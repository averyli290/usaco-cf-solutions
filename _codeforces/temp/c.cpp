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

/*
*/
const long long M = 998244353;
vll factorial;

void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    map<pii, ll> mp;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {max(x, y), min(x, y)};
        mp[a[i]]++;
    }
    sort(all(a));
    reverse(all(a));
    // for(int i = 0; i < n; i++) {
    //     cout << a[i].first << " " << a[i].second << endl;
    // }
    for(int i = 0 ; i < n - 1; i++) {
        if (a[i].first < a[i + 1].first) {
            cout << 0 << endl;
            return;
        }
        if (a[i].second < a[i + 1].second) {
            cout << 0 << endl;
            return;
        }
    }

    ll ans = 1ll;
    for(int i = 0; i < n - 1; i++) {
        pii cur = a[i];
        pii next = a[i + 1];
        // orient 1
        ll temp = 0ll;
        temp += (cur.first - next.first + 1) * (cur.second - next.second + 1);
        // orient 2
        if (cur.first >= next.second && cur.second >= next.first && next.first != next.second) {
            temp += (cur.first - next.second + 1) * (cur.second - next.first + 1);
        }
        ans *= temp;
        ans %= M;
    }

    if (a[0].first != a[0].second) ans *= 2;
    ans %= M;
    for (auto [k, v] : mp) {
        ans *= factorial[v];
        ans %= M;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial.assign(1e5+1, 1);
    factorial[0] = 1ll;
    for(ll i = 1; i <= 1e5; i++) {
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= M;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
