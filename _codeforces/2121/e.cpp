/*
Problem link: https://codeforces.com/contest/2121/problem/E
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
	int l, r; cin >> l >> r;
	string a = to_string(l);
	string b = to_string(r);
	int n = a.length();
	int ans = 0;
	// cout << a << " " << b << ": ";
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {		// first time not equal, a[i] < b[i]
			if (b[i] - a[i] == 1) {		// one will have to match, see which one has more potential to not match later digits
				ans++;
				int ans1 = ans;
				int ans2 = ans;
				for (int j = i + 1; j < n; j++) {
					if (a[j] == '9') {
						ans1++;
					} else {
						break;
					}
				}
				for (int j = i + 1; j < n; j++) {
					if (b[j] == '0') {
						ans2++;
					} else {
						break;
					}
				}
				//cout << ans1 << " " << ans2 << " ";
				cout << min(ans1, ans2) << endl;
				return;
			} else {			// difference is at least 2, can place num in between
				cout << ans << endl;
				return;
			}
		} else {
			ans += 2;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}