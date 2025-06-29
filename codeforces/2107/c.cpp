/*
Problem link: https://codeforces.com/contest/2107/problem/C
*/

#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

/*
ensure that max subarray sum before cannot add up to more than k
if no 0 in s, then, max subarray sum has to be exactly k
if 1 in s and max subarray sum <= k, yes, replace everything
with -1 and one of the 0's with a valid value

*/

void solve() {
	ll n, k; string s; cin >> n >> k;
	cin >> s;
	vll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	vll dp(n, 0);
	ll zero_idx = (ll) -1;
	if (s[0] == '0') {
		dp[0] = (ll) -1;
		zero_idx = 0;
	} else {
		dp[0] = max((ll) 0, a[0]);
	}
	for (ll i = 1; i < n; i++) {
		if (s[i] == '0') {	// reset dp at idx i
			dp[i] = (ll) -1;
			zero_idx = i;
		} else {
			if (dp[i - 1] == (ll) -1) {
				dp[i] = max(a[i], (ll) 0);
			} else {
				dp[i] = max(max(dp[i - 1] + a[i], a[i]), (ll) 0);
			}
		}
	}

	ll max_elt = *max_element(all(dp));

	if (max_elt > k || (zero_idx == -1 && max_elt != k)) {
		cout << "NO" << endl;
		return;
	}

	if (zero_idx == -1 && max_elt == k) {
		cout << "YES" << endl;
		for(ll i = 0; i < n; i++) { cout << a[i] << " "; }
		cout << endl;
		return;
	}

	ll placeholder = -10E14;


	ll left = zero_idx;
	ll right = zero_idx;
	ll cur_sum_right = 0; ll cur_max_right = 0;
	for(ll i = zero_idx + 1; i < n; i++) {	// right
		if (s[i] == '0') { break; }
		else {
			cur_sum_right += a[i];
			if (cur_sum_right > cur_max_right) {
				cur_max_right = cur_sum_right;
				right = i;
			}
		}
	}

	ll cur_sum_left = 0; ll cur_max_left = 0;
	for(ll i = zero_idx - 1; i >= 0; i--) {	// left
		if (s[i] == '0') { break; }
		else {
			cur_sum_left += a[i];
			if (cur_sum_left > cur_max_left) {
				cur_max_left = cur_sum_left;
				left = i;
			}
		}
	}

	//cout << "k before: " << k << endl;
	for (ll i = left; i <= right; i++) {
		if (i != zero_idx) {
			k -= a[i];
		}
	}
	//cout << "k after: " << k << endl;
	a[zero_idx] = k; s[zero_idx] = '1';

	cout << "YES" << endl;
	for(ll i = 0; i < n; i++) {
		if (s[i] == '0') {
			cout << placeholder << " ";
		} else {
			cout << a[i] << " ";
		}
	}
	cout << endl;
	return;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}