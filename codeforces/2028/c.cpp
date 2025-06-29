/*
Problem link: https://codeforces.com/contest/2028/problem/C 
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
	ll n, m, v; cin >> n >> m >> v;
	vector<ll> a(n);

	ll ct = 0;
	for(ll i = 0; i < n; i++) { 
		cin >> a[i];
		if (a[i] > v) {
			ct++;
		}
	}

	// 1 indexed
	vector<ll> l_arr(n + 1);	// l_arr[i] = num monsters can be fed using left inclusive
	vector<ll> r_arr(n + 2);	// r_arr[i] = num monsters can be fed using right inclusive
	vector<ll> pref(n + 1);
	l_arr[0] = 0;
	r_arr[n + 1] = 0;
	pref[0] = 0;

	ll cur = 0;
	for(ll i = 1; i <= n; i++) {
		pref[i] = pref[i - 1]; pref[i] += a[i - 1];
		cur += a[i - 1];
		l_arr[i] = l_arr[i - 1];
		if (cur >= v) {
			cur = 0;
			l_arr[i] += 1;
		}
	}

	cur = 0;
	for(ll i = n; i >= 1; i--){
		cur += a[i - 1];
		r_arr[i] = r_arr[i + 1];
		if (cur >= v) {
			cur = 0;
			r_arr[i] += 1;
		}
	}

	if (r_arr[1] < m && l_arr[n] < m) {
		cout << -1 << endl;
		return;
	}

	ll ans = 0;
	ll right = 1;
	for (ll left = 0; left <= n; left++) {
		ll cur_ans = 0;
		while (right <= n && l_arr[left] + r_arr[right + 1] >= m) {
		//	cout << left << " " << right + 1<< endl;
			right++;
		}

		//cout << right - 1 <<  " " << left << " " << pref[right - 1]<< " " << pref[left] << endl;

		ans = max(pref[right - 1] - pref[left], ans);
	}
	cout << ans << endl;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}