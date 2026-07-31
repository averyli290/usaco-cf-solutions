/*
Problem link: https://codeforces.com/contest/2193/problem/D
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
https://www.youtube.com/watch?v=CINWkIHuB8Q
*/

void solve() {
    int n; cin >> n;
    vll a(n), b(n), pref(n + 1, 0ll);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        pref[i + 1] = pref[i] + b[i];
    }
    int right = n;
    while(pref[right] > n) right--;
    sort(all(a));
    ll ans = 0ll;
    for(int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;
        ll d = a[i];
        ll ct = n - i;
        while(pref[right] > ct) right--;
        ans = max(ans, right * d);
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
