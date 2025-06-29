/*
Problem link: https://codeforces.com/contest/2121/problem/A
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
	int n, s; cin >> n >> s;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << abs(s - a[0]) << endl;
		return;
	}
	
	if (s < a[0]) {
		cout << abs(s - a[n-1]) << endl;
		return;
	}
	if (s > a[n - 1]) {
		cout << abs(s - a[0]) << endl;
		return;
	}

	sort(a.begin(), a.end());

	int x = abs(s - a[0]);
	int y = abs(s - a[n - 1]);

	cout << 2 * min(x, y) + max(x, y) << endl;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}