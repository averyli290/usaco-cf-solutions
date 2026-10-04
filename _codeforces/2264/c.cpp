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

const long long M = 998244353LL;

/*

4
|
3


4
|
3
|
2

4
|\
3 2
*/

void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0 ;i <n ; i++) cin >> a[i];
    sort(all(a));
    reverse(all(a));

    if (n == 1 || a[0] == a[1]) {
        cout << 0 << endl;
        return;
    }
    ll pref = 0;
    ll curct = 0;
    ll ans = 0;
    ll treect = 1;
    for(int i = 1; i < n; i++) {
        pref += a[i - 1];
        pref %= M;


        // debug(prevtot);
        // ans *= i;
        // debug(ans);
        debug(treect);
        debug(pref);
        debug(a[i]);
        ans %= M;
        ans = ans + treect * (pref - (a[i] * i));
        ans %= M;
        // debug(ans);
        treect *= i + 1;
        debug(ans);
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
