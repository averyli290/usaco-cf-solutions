/*
Problem link: https://codeforces.com/contest/2084/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
	ll n, m, k; cin >> n >> m >> k;

	ll l = 0;
	ll h = n;

	vector<ll> ans(n, 0);

	while (h - l > 1) {
		ll mid = (l + h) / 2;
		//cout << l << " " << mid << " " << h << endl;

		bool works = false;
		//cout << m * max(mid, k) + mid  << endl;
		// if trying to achieve mex = mid, then use mid # for spacing
		// if mid < k, still need at least k spaces between identical numbers
		if (
			m * max(mid, k) + mid > n) {
		} else {
			works = true;
			vector<ll> cur_ans(n, n);
			//cout << mid << " " << m << " " << k << endl;
			for (ll i = 0; i < mid; i++) {
				for(ll j = 0; j < m + 1; j++) {
					//cout << i + max(k, mid) * j << " " << n << endl;
					cur_ans[i + max(k, mid) * j] = i;
				}
			}
			ans = cur_ans;
			// for (int i : ans) {
			// 	cout << i << " ";
			// }
			// cout << endl;
		}

		if (works) {
			l = mid;
		} else {
			h = mid;
		}
	}

	for (ll i : ans) {
		cout << i << " ";
	}
	cout << endl;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}