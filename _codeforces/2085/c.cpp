/*
Problem link: https://codeforces.com/contest/2085/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*

(x + k) + (y + k) = (x + k) ^ (y + k)
means that sum with carry is equal to sum without carry
which is the same as thre is no carrying in the original sum, so
(x + k) & (y + k) = 0

can make one of (x + k) or (y + k) some 2^n, where it is greater than the other,
then the & is 0

*/

void solve() {
    ll x, y; cin >> x >> y;
    ll m = max(x,y);
    ll ans = 1 << (64 - __builtin_clzll(m));
    ans -= m;
    if (((x + ans) & (y + ans)) == 0) {
        cout << ans << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}