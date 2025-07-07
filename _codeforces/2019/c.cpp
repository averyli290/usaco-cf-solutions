/*
Problem link: https://codeforces.com/contest/2019/problem/C
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
const long long INF = 1e18;


/*
3 1
3 2 2
1 coin

aaa
bb
cc

needed
0

*/

void solve() {
    ll n, k; cin >> n >> k;
    vll a(n);
    ll total = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    sort(all(a));
    reverse(all(a));
    // need at least max(a) decks
    ll min_decks = *max_element(all(a));

    ll ans = 0;
    ll left = total;
    for(int i = 0; i < n; i++) {
        ll target = i + 1;
        ll needed = min_decks * target;
        // (target - total % target) = how many left over after putting into decks of size target
        needed = max(needed, total + ((target - total % target) % target));
        if (needed <= k + total) {
            ans = target;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
