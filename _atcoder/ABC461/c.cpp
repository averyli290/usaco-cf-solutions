/*
Problem link: https://atcoder.jp/contests/abc461/tasks/abc461_c
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
    int n, k, m; cin >> n >> k >> m;
    vector<vll> a(n, vll{});
    for(int i = 0; i < n; i++) {
        int C; ll V; cin >> C >> V;
        C--;
        a[C].push_back(V);
    }
    vll maxvals;
    for(int i = 0; i < n; i++) {
        if (sz(a[i]) > 0)  {
            sort(all(a[i]));
            maxvals.push_back(*max_element(all(a[i])));
            a[i].pop_back();
        }
    }
    sort(all(maxvals), greater<ll>());
    ll ans = 0ll;
    for(int i = 0; i < m; i++) {
        ans += maxvals[i];
    }
    vll temp;
    temp.insert(temp.end(), maxvals.begin() + m, maxvals.end());
    for(int i = 0; i < n; i++) {
        temp.insert(temp.end(), all(a[i]));
    }
    sort(all(temp), greater<ll>());
    for(int i = 0; i < k - m; i++) {
        ans += temp[i];
    }
    cout << ans << endl;
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
